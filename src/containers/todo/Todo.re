open Utils;
open Reasy;
open TodoShared;

importAsset("./style.scss");

type state = {tasks: list(task)};

type action =
  | NewTask(task);

/**
 * Functions
 */
let taskFactory = name => {name, id: "DSADIOJSAID", completed: false};

/**
 * Component
*/
let reducer = (action, state) =>
  switch (action) {
  | NewTask(newTask) => setState({tasks: [newTask, ...state.tasks]})
  };

let component = reducerFactory("Todo");

let make = _children => {
  ...component,
  reducer,
  initialState: () => {tasks: []},
  render: ({send, state}) =>
    <div className="todo-container">
      <AddTodo
        onAddNewTodo={taskName => taskName->taskFactory->NewTask->send}
      />
      <TodoList tasks={state.tasks} />
    </div>,
};
