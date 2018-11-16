open Utils;

importAsset("./global.scss");

let appContainer = "app-container";

ReactDOMRe.renderToElementWithId(<App />, appContainer);

if (Utils.hot) {
  Utils.accept();
};
