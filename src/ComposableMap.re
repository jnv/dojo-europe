[@bs.module "react-simple-maps"]
external composableMap : ReasonReact.reactClass = "ComposableMap";

type projection = {
  scale: int,
  rotation: array(int),
};

[@bs.deriving abstract]
type jsProps = {
  projectionConfig: projection,
  width: int,
  height: int,
};

let make = (~projectionConfig, ~width, ~height, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=composableMap,
    ~props=jsProps(~projectionConfig, ~width, ~height),
    children,
  );