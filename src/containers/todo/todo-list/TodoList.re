open Reasy;

let component = ReasonReact.statelessComponent("TodoList");

let items = ["1", "2", "3", "4"];

let make = (~tasks: list(TodoShared.task), _children) => {
  ...component,
  render: _self =>
    <ul>
      {
        tasks
        ->map(task => <li key={task.name}> task.name->strfy </li>)
        ->arrayfy
      }
    </ul>,
};
