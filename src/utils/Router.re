module RRouter = ReasonReact.Router;

let goTo = route => RRouter.push(route);
let watchUrl = RRouter.watchUrl;
let unwatchUrl = RRouter.unwatchUrl;
let initialUrl = RRouter.dangerouslyGetInitialUrl;
