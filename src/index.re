open Utils;

importAsset("./global.css");

let appContainer = "app-container";

ReactDOMRe.renderToElementWithId(<App />, appContainer);

if (Utils.hot) {
  Utils.accept();
};
