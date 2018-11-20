type model = {
    tasks: list(TodoShared.task),
    completeTodo: TodoShared.task => unit
};

module TodoContext = Context.MakePair({
    type t = model;
    let defaultValue = { tasks: [], completeTodo: _ => () };
});
