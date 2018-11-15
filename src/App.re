open Router;

/**
 * Types
 */
type route =
  | Home;

type action =
  | ChangeRoute(route);

type state = {route};

/**
 *
 * Functions
 */
let unmountWatchUrl = (id, _) => unwatchUrl(id);

let pageFromRoute = route =>
  switch (route) {
  | Home => <Home />
  };

let routeFromPath = path =>
  switch (path) {
  | ["route-1"] => Home
  | _ => Home
  };

let getCurrentRoute = () => initialUrl().path->routeFromPath;

/**
 * Component
 */
let reducer = (action, _state) =>
  switch (action) {
  | ChangeRoute(route) => ReasonReact.Update({route: route})
  };

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,
  reducer,
  initialState: () => {route: getCurrentRoute()},
  didMount: self => {
    let watcherId =
      watchUrl(url => {
        let route = url.path->routeFromPath->ChangeRoute;
        self.send(route);
      });

    self.onUnmount(unmountWatchUrl(watcherId));
  },
  render: self => <> {pageFromRoute(self.state.route)} </>,
};
