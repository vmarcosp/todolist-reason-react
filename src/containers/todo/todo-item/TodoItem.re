open TodoShared;
open Utils;
open Reasy;

cssfy("./style.scss");


let getItemClass = completed => completed ? "infos completed" : "infos";

/**
* Component 
*/
let component = ReasonReact.statelessComponent("TodoItem")

let make = (~task: task, ~onComplete, _children) => {
    ...component,
    render: _self => 
    <li className="todo-item">
        <div className={getItemClass(task.completed)}>
            <span className="name">{strfy(task.name)}</span>
            <span className="date">{strfy("12 de novembro, 11:55pm")}</span>
        </div>
        <Checkbox
            value=task.completed
            onChange={onComplete} />
    </li>
};
