[@bs.module "react-simple-maps"]
external geographies : ReasonReact.reactClass = "Geographies";

[@bs.deriving abstract]
type jsProps = {geography: string};

let make = (~geography, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=geographies,
    ~props=jsProps(~geography),
    children,
  );