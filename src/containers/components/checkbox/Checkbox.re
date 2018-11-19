open Utils;
open Reasy;
/**
 * Imports
 */
cssfy("./style.scss");

let checkIcon = import("./icon.svg");

/**
 * Types
*/

let component = ReasonReact.statelessComponent("Checkbox");

let make = (~onChange, ~value: bool, _children) => {
    ...component,
    render: _self =>
    <label className="checkbox">
        <input 
            checked=value
            onChange=onChange
            type_="checkbox"/>
        <div className="real-checkbox">
            <img 
                src={checkIcon} 
                alt="Checked Icon"/>
        </div>
    </label>
}
