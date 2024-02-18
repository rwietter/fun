### ``` as const ```

Uma declaração const é uma asserção de tipo especial que usa a palavra-chave const ao invés de um nome de tipo específico. Usar uma declaração const em uma expressão literal tem os seguintes efeitos:

- Nenhum tipo literal na expressão literal será ampliado.
- Literais de objeto obterão propriedades readonly.
- Literais de arrays se tornarão tuplas readonly.

Ex:

```typescript
const HTTPRequestMethod = {
  CONNECT: "CONNECT",
  DELETE: "DELETE",
  GET: "GET",
  HEAD: "HEAD",
  OPTIONS: "OPTIONS",
  PATCH: "PATCH",
  POST: "POST",
  PUT: "PUT",
  TRACE: "TRACE"
} as const;
```

É igual a:

```typescript
const HTTPRequestMethod: {
  readonly CONNECT: "CONNECT";
  readonly DELETE: "DELETE";
  readonly GET: "GET";
  readonly HEAD: "HEAD";
  readonly OPTIONS: "OPTIONS";
  readonly PATCH: "PATCH";
  readonly POST: "POST";
  readonly PUT: "PUT";
  readonly TRACE: "TRACE";
} = {
  CONNECT: "CONNECT",
  DELETE: "DELETE",
  GET: "GET",
  HEAD: "HEAD",
  OPTIONS: "OPTIONS",
  PATCH: "PATCH",
  POST: "POST",
  PUT: "PUT",
  TRACE: "TRACE"
};
```

---

Isso pode ser aplicado para:

- literais de strings
- literais numbers
- literais booleans
- literais de arrays
- literais de objects

---

```typescript
const ORIGIN = {
  x: 0,
  y: 0
} as const;
```

```typescript
const ORIGIN = [0, 0] as const;
```

```typescript
function rollDice(): 1 | 2 | 3 | 4 | 5 | 6 {
  return (Math.floor(Math.random() * 6) + 1) as 1 | 2 | 3 | 4 | 5 | 6;
}

const result = rollDice();
```