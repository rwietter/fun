/**
 * Implement the built-in Omit<T, K> generic without using it.
 * Constructs a type by picking all properties from T and then removing K
 * 
 * For example:
 */

type MyOmit<T, K> = {
  [I in keyof T as I extends K ? never : I]: T[I]
}

interface Todo {
  title: string
  description: string
  completed: boolean
}

type TodoPreview = MyOmit<Todo, 'description' | 'title'>
//    ^?

const todo: TodoPreview = {
  completed: false,
}


export {}
