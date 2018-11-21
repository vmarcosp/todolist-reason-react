open Utils;
open Reasy;
open TodoShared;
open TodoContext;
open List;

cssfy("./style.scss");

type state = {tasks: list(task)};

type action =
  | NewTask(task)
  | CompleteTask(task);

/**
 * Functions
 */
let taskFactory = name => { name, completed: false, createdAt: Js.Date.now() };

let completeTask = ({ tasks }, task) => {
  let filteredTasks = tasks 
                      |> filter(currentTask => currentTask.name !== task.name)

  let completedTask = {
    ...task,
    completed: !task.completed
  };

  setState({ tasks: [completedTask, ...filteredTasks] });
};


/**
 * Component
*/
let reducer = (action, state) =>
  switch (action) {
  | NewTask(newTask) => setState({tasks: [newTask, ...state.tasks]})
  | CompleteTask(task) => completeTask(state, task)
  };

let component = ReasonReact.reducerComponent("Todo");

let make = _children => {
  ...component,
  reducer,
  initialState: () => { tasks: [] },
  render: ({send, state}) =>

  <TodoContext.Provider value={ 
      tasks: state.tasks, 
      completeTodo: task => send(CompleteTask(task))
    }>
      <div className="todo-container">
        <Logo />
        <AddTodo
          onAddNewTodo={taskName => taskName->taskFactory->NewTask->send}
        />
        <TodoList />
      </div>
  
  </TodoContext.Provider>,
};
