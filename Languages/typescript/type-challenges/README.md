
## Keywords do TypeScript

### EXTENDS

Para simplificar, você pode pensar como se fosse nosso querido velho JavaScript ===.
Quando você faz isso, pode ver um extends declaração como ternário simples, e então se torna
muito mais simples de entender. Nesse caso, extends é referido como um tipo condicional.

```ts
type MyType<T> = T extends string ? string : number;
```

### TYPE

Uma função, mas para tipos. Possui uma entrada, que são tipos (chamados genéricos) e
tem uma saída. A saída depende da lógica de um tipo, e extends é esse bloco de lógica,
semelhante a um if cláusula ( ou ternária ).

```ts
type MyType<T> = {
  [K in keyof T]: T[K] extends string ? string : number;
};
```

### INFER

É a lupa do TypeScript, uma bela ferramenta de inspeção que pode extrair tipos
que estão presos dentro de diferentes tipos de estruturas!

```ts
type ObjectInfer<O> = O extends { a: Infer A } ? A : never
```

### IN

É uma maneira de iterar sobre os tipos de uma estrutura de dados. Por exemplo, se você
tiver um objeto, você pode iterar sobre suas chaves e valores.

```ts
type MyType<T> = {
  [K in keyof T]: T[K] extends string ? string : number;
};
```

### KEYOF

É uma maneira de obter todas as chaves de um tipo. Por exemplo, se você tiver um objeto,
você pode obter todas as chaves do objeto.

```ts
type MyType<T> = {
  [K in keyof T]: T[K] extends string ? string : number;
};
```
