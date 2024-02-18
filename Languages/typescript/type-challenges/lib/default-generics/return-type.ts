// ----------------------------------------------------------------
// ReturnType
// ----------------------------------------------------------------
export const foo = (a: number, b: string) => a + b;
type Return = ReturnType<typeof foo>; // type de retorno da função


