open Reasy;
open Utils;

cssfy("./style.scss");

let component = ReasonReact.statelessComponent("Footer")

let make = _children => {
    ...component,
    render: _self => {
        <div className="footer-container">
            {strfy("Made with Reason and React ")}
            <span className="icon">{strfy(" <3")}</span>            
        </div>
    }
}
