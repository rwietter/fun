// import Radixsort from "../Radixsort.ts";
const MaxValue = require("../maxvalue.js");

test('Max value should 77', () => {
  const arr = [1, 4, 6, 3, 2, 66, 3, 32, 77, 32];
  const len = arr.length;
  expect(MaxValue(arr, len)).toBe(77);
});

test('Max value should be 4994949', () => {
  const arr = [835, 553, 48, 0, 0, 2303, 934, 4994949, 0, 1, 2];
  const len = arr.length
  expect(MaxValue(arr, len)).toBe(4994949);
})
