[@bs.module "react-simple-maps"]
external geographyComponent : ReasonReact.reactClass = "Geography";

type geographyType;

type projectionT;

[@bs.deriving abstract]
type styleT = {
  default: ReactDOMRe.Style.t,
  hover: ReactDOMRe.Style.t,
  pressed: ReactDOMRe.Style.t,
};

[@bs.deriving abstract]
type jsProps = {
  geography: geographyType,
  projection: projectionT,
  style: styleT,
};

let make = (~geography, ~projection, ~style) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=geographyComponent,
    ~props=jsProps(~geography, ~projection, ~style),
  );