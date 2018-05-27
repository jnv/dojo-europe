let component = ReasonReact.statelessComponent("Greeting");

let geoStyle =
  Geography.styleT(
    ~default=
      ReactDOMRe.Style.make(
        ~fill="#ECEFF1",
        ~stroke="#607D8B",
        ~strokeWidth="0.75",
        ~outline="none",
        (),
      ),
    ~hover=
      ReactDOMRe.Style.make(
        ~fill="#607D8B",
        ~stroke="#607D8B",
        ~strokeWidth="0.75",
        ~outline="none",
        (),
      ),
    ~pressed=
      ReactDOMRe.Style.make(
        ~fill="#FF5722",
        ~stroke="#607D8B",
        ~strokeWidth="0.75",
        ~outline="none",
        (),
      ),
  );

let make = _children => {
  ...component,
  render: _self =>
    <ComposableMap
      projectionConfig={scale: 200, rotation: [|(-11), 0, 0|]}
      width=980
      height=551>
      <ZoomableGroup center=(0, 20) disablePanning=true>
        <Geographies geography="/world-50m.json">
          ...(
               (geographies, projection) =>
                 geographies
                 |> Array.mapi((i, geo) =>
                      <Geography
                        key=(string_of_int(i))
                        geography=geo
                        style=geoStyle
                        projection
                      />
                    )
             )
        </Geographies>
      </ZoomableGroup>
    </ComposableMap>,
};
/* (geographies, projection) => Array.map((geography) => ReasonReact.string(geography), geographies) */