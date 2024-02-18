type todo = {
  title: string,
  description: string,
  complet: boolean
};

type FinishTodo = {
  complet: boolean;
};

/* ───────────────────────────────────────
  Exclude from T those types that are
  assignable to U
─────────────────────────────────────── */
type todoBody = Exclude<FinishTodo, todo>;

const Tasks: todoBody = {
  complet: false
}