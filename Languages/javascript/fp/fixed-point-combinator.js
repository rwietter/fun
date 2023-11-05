/**
 * Fixed point combinator (Y combinator) and self-application (referential) functions
 * 
 * 1. Factorial is called with 3 as argument
 * 2. Y combinator is called with factorial as argument
 * 3. Y combinator returns a function that is called with factorial as argument
 * 4. The returned function is called with 3 as argument (n = 3)
 * 5. The returned function calls factorial with 2 as argument (n = 2)
 */

// ((x) => x(x)) => chama self com a função como argumento
// (x => fn(y => x(x)(y))) => realiza a chamada recursiva
// const Y = (fn) => ((x) => x(x))(x => fn(y => x(x)(y)));
// const factorial = Y((self) => (n) => (n <= 1 ? 1 : n * self(n - 1)));

// factorial(3)

/* Y-combinator
const f = x => x(x)((x) => x(x));
f((self) => (hello) => self(console.log(hello)));
*/

const Y = (gen) => ((f) => f(f))((f) => gen((x) => f(f)(x)));
const factorialGen = (fact) => (n) => (n <= 1 ? 1 : n * fact(n - 1));
const factorial = Y(factorialGen);
console.log(factorial(5));