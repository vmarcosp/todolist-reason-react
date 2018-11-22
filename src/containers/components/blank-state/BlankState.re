open Utils;
open Reasy;

cssfy("./style.scss");  

let icon = import("./icon.svg");

let component =  ReasonReact.statelessComponent("BlankState")

let make = _children => {
    ...component,
    render: _self => 
    <div className="blank-state-container">
        <img
            src={icon} 
            alt="Blank State Icon" 
            className="icon"
        />
        <span className="message">{strfy("Nothing todo")}</span>
    </div>
}
