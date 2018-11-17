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
let taskFactory = name => {name, completed: false};

/**
 * Component
*/
let reducer = (action, state) =>
  switch (action) {
  | NewTask(newTask) => setState({tasks: [newTask, ...state.tasks]})
  };

let allTasks = [{
  name: "Go to the market",
  completed: false,
},
{
  name: "Yoga class",
  completed: false,
},
{
  name: "Party",
  completed: false,
}
]

let component = reducerFactory("Todo");

let make = _children => {
  ...component,
  reducer,
  initialState: () => {tasks: allTasks},
  render: ({send, state}) =>
    <div className="todo-container">
      <AddTodo
        onAddNewTodo={taskName => taskName->taskFactory->NewTask->send}
      />
      <TodoList tasks={state.tasks} />
    </div>,
};
