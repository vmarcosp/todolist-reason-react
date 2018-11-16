open Reasy;

let component = ReasonReact.statelessComponent("Other");

let make = (~name: string, _children) => {
  ...component,
  render: _self => <div> {strfy(name)} </div>,
};
