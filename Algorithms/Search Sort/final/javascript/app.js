const Radix = require('./radixsort.js');

const app = () => {
  const array = [55, 3, 77, 4, 4, 2, 55, 0, 46, 7, 8];
  console.log("unsorted -> array", array)
  const len = array.length;
  Radix(array, len);
  console.log("sorted -> array", array)
}

app();
