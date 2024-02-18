type Person = {
  jose: {
    abc: string;
  };
  carlos: {
    def: string;
  };
  maria: {
    ghi: string;
  };
};

type ObjectKey = {
  [K in keyof Person]: {
    pessoa: K;
    valor: Person[K];
  }
}[keyof Person];

const teste: ObjectKey = {
  pessoa: "maria",
  valor: {
    ghi: "teste",
  },
};
