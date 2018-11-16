open Reasy;

let component = ReasonReact.statelessComponent("TodoList");

let make = _children => {
  ...component,
  render: _self =>
    <ul>
      <li> {strfy("Item 1")} </li>
      <li> {strfy("Item 1")} </li>
      <li> {strfy("Item 1")} </li>
      <li> {strfy("Item 1")} </li>
      <li> {strfy("Item 1")} </li>
    </ul>,
};
