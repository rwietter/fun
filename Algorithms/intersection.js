const array1 = [1, 2, 3];
const array2 = [2, 3, 4];

const set2 = new Set(array2);

// Intersection - elements present in both sets
const intersection = new Set([...array1].filter(x => set2.has(x)));
const r = Array.from(intersection) // Output: [2, 3]
