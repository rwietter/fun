// ----------------------------------------------------------------
// Parameters
// ----------------------------------------------------------------

export const foo = (a: number, b: string) => a + b;

type Params = Parameters<typeof foo>; // parâmetros da função

// Programming Parameters
type TParams<F extends (...args: any[]) => any> =
  F extends ((...args: infer A) => any) ? A : never

// then
const user: TParams<typeof foo> = [1, 'a'];

