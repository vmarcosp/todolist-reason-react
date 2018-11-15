[@bs.val] external hot: bool = "module.hot";

[@bs.val] external accept: unit => unit = "module.hot.accept";

[@bs.val] external importAsset: string => unit = "require";
