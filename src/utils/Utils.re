[@bs.val] external hot: bool = "module.hot";

[@bs.val] external accept: unit => unit = "module.hot.accept";

[@bs.val] external cssfy: string => unit = "require";

[@bs.val] external import: string => string = "require";
