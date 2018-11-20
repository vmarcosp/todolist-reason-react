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
        {tasks
          ->mapfy(task => <TodoItem onComplete={_ => completeTodo(task)} key={task.name} task={task} />)
          ->arrayfy
        }
      </ul>
    )}
  </TodoContext.Consumer>
    ,
};


