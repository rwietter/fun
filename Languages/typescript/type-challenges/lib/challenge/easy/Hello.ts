/**
 * 1. Hello World
 * 
 * In Type Challenges, we use the type system itself to do the assertion.
 * For this challenge, you will need to change the following code to make the tests pass (no type check errors).
 * 
 * Exercise:
 * ❌ type HelloWorld = any
 * ✅ type HelloWorld = string // change this to a string type
 */
type HelloWorld = string;


/* _____________ Test Cases _____________ */
import type { Equal, Expect, NotAny } from '@type-challenges/utils'
type cases = [
  Expect<NotAny<HelloWorld>>,
  Expect<Equal<HelloWorld, string>>,
]
