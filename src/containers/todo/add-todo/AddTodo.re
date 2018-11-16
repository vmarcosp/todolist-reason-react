open Reasy;

type state = {taskName: string};
type action =
  | HandleInputChange(string);

/**
 *
 * Component
 */

let reducer = (action, _state) =>
  switch (action) {
  | HandleInputChange(taskName) => ReasonReact.Update({taskName: taskName})
  };

let component = ReasonReact.reducerComponent("AddTodo");

let make = _children => {
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
        onChange={
          event =>
            event
            ->ReactEvent.Form.target
            ->getEventValue
            ->HandleInputChange
            ->send
        }
      />
      <button onClick={_event => Js.log(state.taskName)} className="button">
        {strfy("Add")}
      </button>
    </div>,
};
