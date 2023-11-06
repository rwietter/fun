const pair = (a, b) => (f) => f(a, b);

const myPair = pair(3, 7);

const firstElement = myPair((a, b) => b);
const secondElement = myPair((a, b) => a);

console.log("First element:", firstElement); // Output: 3
console.log("Second element:", secondElement); // Output: 7
