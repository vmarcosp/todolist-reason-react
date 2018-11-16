let strfy = ReasonReact.string;
let intfy = v => strfy(string_of_int(v));
let getEventValue = target => target##value;
let setState = value => ReasonReact.Update(value);
let reducerFactory = name => ReasonReact.reducerComponent(name);
