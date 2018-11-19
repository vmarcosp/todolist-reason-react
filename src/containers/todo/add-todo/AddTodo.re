open Reasy;
open Utils;

cssfy("./style.scss");

/**
 * Types
 */
type state = {taskName: string};

type action =
  | HandleInputChange(string)
  | ClearInput;

/**
 *
 * Functions
 */
let transformEvent = event =>
  event->ReactEvent.Form.target->getEventValue->HandleInputChange;

/**
 *
 * Component
 */
let reducer = (action, _state) =>
  switch (action) {
  | HandleInputChange(taskName) => setState({taskName: taskName})
  | ClearInput => setState({taskName: ""})
  };

let component = reducerFactory("AddTodo");

let make = (~onAddNewTodo, _) => {
  ...component,
  reducer,
  initialState: () => {taskName: ""},
  render: ({send, state}) =>
    <div className="add-todo-container">
      
      <input
        placeholder="Type your task name"
        type_="text"
        className="input"
        value={state.taskName}
        onChange={event => event->transformEvent->send}
      />
     
      <button
        className="button"
        onClick={_event => {
            onAddNewTodo(state.taskName);
            send(ClearInput);
          }}>
        {strfy("Add new task")}
      </button>

    </div>,
};
