open Utils;

importAsset("./style.scss");

type todo = {
  id: string,
  name: string,
  completed: bool,
};

let component = ReasonReact.statelessComponent("Todo");

let make = _children => {
  ...component,
  render: _self =>
    <div className="todo-container">
      <AddTodo onAddNewTodo={taskName => Js.log("here =>" ++ taskName)} />
      <TodoList />
    </div>,
};
