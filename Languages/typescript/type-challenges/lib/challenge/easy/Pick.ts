/**
 * Implement the built-in Pick<T, K> generic without using it
 * Constructs a type by picking the set of properties K from T
 *
 * For example:
 * interface Todo {
 *  title: string
 *  description: string
 *  completed: boolean
 * }
 *
 * type TodoPreview = MyPick<Todo, 'title' | 'completed'>
 * const todo: TodoPreview = { title: 'Clean room', completed: false, }
 */

/**
 * ```ts
 *                 | valid key    |
 * type MyPick<T, K extends keyof T> = {
 *   [I in K]: I extends K ? T[I] : never;
 * }
 *
 * type MyPick<T, K> = {
 *     | invalid extends |
 *  [I extends keyof K]: I extends keyof T ? T[I] : never;
 * }
 * ```
 */

/**
 * T = Todo
 * "K extends keyof T" significa que K é igual as chaves de T (title, completed)
 * K = 'title' | 'completed'
 * [I] = title, completed
 * [K] = [title, completed]
 * I extends K siginifica que I é igual a K (title, completed)
 * I === K[idx] ? Todo[I] : nada
 */

type MyPick<T, K extends keyof T> = { [I in K]: T[I] };

interface Todo {
	title: string;
	description: string;
	completed: boolean;
}

type TodoPreview = MyPick<Todo, "title" | "completed">;
//    ^?

const todo: TodoPreview = {
	title: "Clean room",
	completed: false,
};

import type { Equal, Expect } from "@type-challenges/utils";

interface P1 {
	title: string;
}

interface P2 {
	title: string;
	completed: boolean;
}

type cases = [
	Expect<Equal<P1, MyPick<Todo, "title">>>,
	Expect<Equal<P2, MyPick<Todo, "title" | "completed">>>,
];
