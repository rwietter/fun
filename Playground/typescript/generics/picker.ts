type Picker<O, K extends keyof O> = {
  [P in K]: O[P];
};

type Todos = {
  title: string;
  description: string;
  complet: boolean;
};

type obj = Picker<Todos, "title">;
