type Arr1 = readonly any[];
type Arr2 = number[];

function concat<T extends Arr1, U extends Arr2>(arr1: T, arr2: U): [...T, ...U] {
  return [...arr1, ...arr2];
}


// ------------------------------------

type array = readonly unknown[];

function partialCall<T extends array, U extends array, R>(
  f: (...args: [...T, ...U]) => R,
  ...headArgs: T
) {
  return (...tailArgs: U) => f(...headArgs, ...tailArgs);
}

const foo = (x: string, y: number, z: boolean) => {
  //...
};

const f3 = partialCall(foo, "hello");
