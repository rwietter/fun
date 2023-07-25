function tail<T extends unknown[]>(arr: readonly [any, ...T]) {
  const [_ignored, ...rest] = arr;
  return rest;
}

const myTuple = [1, 2, 3, 4] as const;
const myArray = ["hello", "world"];

const r1 = tail(myTuple);
//    ^ = const r1: [2, 3, 4]

const r2 = tail([...myTuple, ...myArray] as const);
//    ^ = const r2: [2, 3, 4, ...string[]]

// ---------------------------------------------

type DataType = number[] | string[];

function concatData<T extends DataType, U extends DataType>
(arr1: T, arr2: U): [...T, ...U] {
  return [...arr1, ...arr2];
}

concatData([1,2,3,4], ['Hello', 'World'])
