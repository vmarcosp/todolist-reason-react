open TodoShared;
open Utils;
open Reasy;

importAsset("./style.scss");

let component = ReasonReact.statelessComponent("TodoItem")

let make = (~task: task, _children) => {
    ...component,
    render: _self => <li className="todo-item">
        <span className="name">{strfy(task.name)}</span>
    </li>
};
