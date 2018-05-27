[@bs.module "react-simple-maps"]
external zoomableGroup : ReasonReact.reactClass = "ZoomableGroup";

[@bs.deriving abstract]
type jsProps = {
  disablePanning: bool,
  center: (int, int),
};

let make = (~center, ~disablePanning, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=zoomableGroup,
    ~props=jsProps(~center, ~disablePanning),
    children,
  );