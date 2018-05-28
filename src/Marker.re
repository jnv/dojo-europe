[@bs.module "react-simple-maps"]
external markerComponent : ReasonReact.reactClass = "Marker";

[@bs.deriving abstract]
type markerT = {
  coordinates: (float, float),
  name: string,
  markerOffset: int,
};

[@bs.deriving abstract]
type jsProps = {
  marker: markerT,
  style: Geography.styleT,
};

let make = (~marker, ~style, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=markerComponent,
    ~props=jsProps(~marker, ~style),
    children,
  );