const array1 = [1, 2, 3];
const array2 = [2, 3, 4];

const set1 = new Set(array1);
const set2 = new Set(array2);

// Union - elements present in either set
const union = new Set([...set1, ...set2]); // [1, 2, 3, 4]
