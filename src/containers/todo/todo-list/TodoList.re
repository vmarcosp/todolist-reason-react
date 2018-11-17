open Reasy;
open TodoShared;
open Utils;

importAsset("./style.scss");

let component = ReasonReact.statelessComponent("TodoList");

let make = (~tasks: list(task), _children) => {
  ...component,
  render: _self =>
    <ul className="todo-list-container">
      {
        tasks
        ->mapfy(task => <TodoItem key={task.name} task={task} />)
        ->arrayfy
      }
    </ul>,
};
