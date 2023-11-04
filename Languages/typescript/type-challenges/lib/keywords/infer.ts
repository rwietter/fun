/**
 * Infer object type properties
 */
type InferObject<O> = O extends { name: infer V } ? V : never;
const obj = { name: 'hello' };
type Obj = InferObject<typeof obj>
//   ^?



/**
 * Infer function type properties
 */
type InferFunction<F> = F extends (a: infer A, b: infer B) => infer R ? { a: A, b: B, c: R } : never;

// incorrect type | type AddNumber = number;
type AddNumber = number;
type AddNumberInfer = InferFunction<AddNumber>
//    ^?

// correct type | InferFunction<AddFunction>
type AddFunction = (a: number, b: string) => number;
type AddFunctionInfer = InferFunction<AddFunction>;
//    ^?
const inferedFunction: AddFunctionInfer = { a: 1, b: 'infered', c: 2}; // result of inference params with return type


/**
 * Infer Promise type return properties
 */
type ClassInfer<I> = I extends (...args: any) => Promise<infer G> ? G : never;
const classInfer = () => Promise.resolve([1, 2, 3]);
type InferPromise = ClassInfer<typeof classInfer>;
//   ^?


/**
 * Infer Array type properties
 */
type ArrayInfer<T> = T extends (infer U)[] ? U : never;
const arrayInfer = [1, 2, 'rwietter'];
type InferArray = ArrayInfer<typeof arrayInfer>;
//   ^?
