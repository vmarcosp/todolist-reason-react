open Belt;

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
let setState = value => ReasonReact.Update(value);
let reducerFactory = name => ReasonReact.reducerComponent(name);
