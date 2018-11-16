open Reasy;
open TodoShared;

let component = ReasonReact.statelessComponent("TodoList");

let make = (~tasks: list(task), _children) => {
  ...component,
  render: _self =>
    <ul>
      {
        tasks
        ->mapfy(task => <TodoItem key={task.name} task={task} />)
        ->arrayfy
      }
    </ul>,
};
