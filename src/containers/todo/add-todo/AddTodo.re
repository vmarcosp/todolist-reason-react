open Reasy;

let component = ReasonReact.statelessComponent("AddTodo");

let make = _children => {
  ...component,
  render: _self =>
    <div className="add-todo-container">
      <input
        placeholder="Type your task name"
        type_="text"
        className="input"
      />
      <button className="button"> {strfy("Add")} </button>
    </div>,
};
