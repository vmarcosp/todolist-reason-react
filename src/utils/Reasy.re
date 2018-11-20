open Belt;

type context;

[@bs.get] external provider: context => ReasonReact.reactClass = "Provider";
[@bs.get] external consumer: context => ReasonReact.reactClass = "Consumer";
[@bs.module "react"] external createContext: 'a => context = "";


/**
* Render utils 
*/
let strfy = ReasonReact.string;
let intfy = v => v->string_of_int->strfy;
let boolfy = v => v->string_of_bool->strfy;
let arrayfy = v => ReasonReact.array(v);
let mapfy = (v, cb) => List.toArray(List.map(v, cb));

let getCheckboxValue = event => {
    let t = event->ReactEvent.Form.target
    t##checked;
}

let getEventValue = target => target##value;

/**
* ReasonReact utils
*/
let setState = value => ReasonReact.Update(value);
