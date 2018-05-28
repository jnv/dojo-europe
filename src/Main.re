type state = array(Marker.markerT);

/* type data = array; */
type action =
  | FetchData
  | PostData
  | LoadData(array(Fetcher.data));
let component = ReasonReact.reducerComponent("Main");

let make = _children => {
  ...component,
  initialState: _state => [||],
  reducer: (action, state) =>
    switch (action) {
    | PostData =>
      ReasonReact.UpdateWithSideEffects(
        state,
        (
          _self =>
            Fetcher.fetchPost(
              ~url="https://immense-river-25513.herokuapp.com/add-location",
              ~body="jnv",
            )
        ),
      )
    | FetchData =>
      ReasonReact.UpdateWithSideEffects(
        state,
        (
          self =>
            Fetcher.fetchGet(
              ~url="https://immense-river-25513.herokuapp.com/locations",
              ~cb=items =>
              self.send(LoadData(items))
            )
        ),
      )
    | LoadData(items) =>
      items
      |> Array.map(item => {
           let (long, lat) = Fetcher.location(item);
           Marker.markerT(
             ~name=Fetcher.username(item),
             ~coordinates=(lat, long),
             ~markerOffset=-25,
           );
         })
      |> (newItems => ReasonReact.Update(newItems))
    },
  didMount: self => {
    self.send(PostData);
    self.send(FetchData);
  },
  render: self => <Map markers=self.state />,
};