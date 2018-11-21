open Utils;
open Reasy;

cssfy("./style.scss");

let icon = import("./icon.svg");

let component = ReasonReact.statelessComponent("Logo");

let make = _children => {
    ...component,
    render: _self => 
    <div className="logo-container">
        <span className="name">
            {strfy("TodoList")}
        </span>
        <img src={icon} alt="Logo icon"/>
    </div>
};
