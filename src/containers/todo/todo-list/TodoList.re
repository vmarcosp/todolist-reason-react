open Reasy;
open Utils;
open TodoContext;

cssfy("./style.scss");

let component = ReasonReact.statelessComponent("TodoList");

let make = (_children) => {
  ...component,
  render: _self =>
  <TodoContext.Consumer>
    ...{({ completeTodo, tasks }) => (
      <ul className="todo-list-container">
        {
          if(List.length(tasks) > 0)
            tasks
              ->mapfy(task => <TodoItem onComplete={_ => completeTodo(task)} key={task.name} task={task} />)
              ->arrayfy
          else
            <BlankState />
        }
      </ul>
    )}
  </TodoContext.Consumer>
    ,
};


