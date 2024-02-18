const arr1 = ['a', 'b', 'c', 'x'];
const arr2 = ['z', 'y', 'a'];

// Solution 1
// O(n+m) time complexity, because we have to iterate over both arrays
// O(n) space complexity, because we have to create a new dictionary
const dict = {}
arr1.forEach(el => dict[el] ? dict[el]++ : dict[el] = 1)
arr2.forEach(el => dict[el] ? dict[el]++ : dict[el] = 1)
const r = Object.keys(dict).reduce(el => dict[el] > 1 ? true : false)
console.log(r)

// Solution 2
// O(n+m) time complexity, because filter array1 and create Set with array2
// O(n) space complexity, because we have to create a new Set
const containsDuplicatedElements = () => {
  return arr1.filter(el => new Set(arr2).has(el)).length ? true : false;
}
console.log(containsDuplicatedElements());

// Solution 3
// O(n+m) time complexity, because we have to iterate over both arrays
// O(1) space complexity, because we don't create any new data structure
const containsDuplicatedEls = () => {
  return arr1.some(item => arr2.includes(item))
}
console.log(containsDuplicatedEls())
