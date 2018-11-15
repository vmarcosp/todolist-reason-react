open Reasy;
open Utils;

importAsset("./Home.css");

let component = ReasonReact.statelessComponent("Home");

let make = _children => {
  ...component,
  render: _self =>
    <div className="container"> <span> {strfy("Home page...")} </span> </div>,
};
