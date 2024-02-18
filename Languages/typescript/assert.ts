function assertNonNullish<T>(
  value: T,
  message: string
): asserts value is NonNullable<T> {
  if (value === null || value === undefined || value === undefined) {
    throw new Error(message);
  } 
}

/* -------------------------------------------------------------------- */

function assertAllPositiveNumbers(arr: number[]): asserts arr is number[] {
  if (arr.some((num) => num <= 0)) {
    throw new Error("Array contains non-positive numbers.");
  }
}

const numbers: number[] = [1, 2, 3, -4];

try {
  assertAllPositiveNumbers(numbers); // Error: Array contains non-positive numbers.
  console.log(numbers.reduce((acc, val) => acc + val));
} catch (e: unknown) {
  console.log(e);
}

/* -------------------------------------------------------------------- */

function assertHasProperty<T, K extends string>(
  obj: T,
  key: K
): asserts obj is T & Record<K, any> {
  if (!(key in (<never>obj))) {
    throw new Error(`Object does not have the property ${key}.`);
  }
}

try {
  const person: unknown = { name: "Alice", age: 30 };
  assertHasProperty(person, "age");
  console.log(person.age);
  assertHasProperty(person, "a");
  console.log(person.a);
} catch (e: unknown) {
  console.log((<{ message: string }>e).message);
}
