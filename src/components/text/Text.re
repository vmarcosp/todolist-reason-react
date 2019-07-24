open Reasy;

let component = ReasonReact.statelessComponent("Text");

let make = (~value,_) => {
    ...component,
    render: _self => 
      <span>
          {strfy(value)}
      </span>
};
