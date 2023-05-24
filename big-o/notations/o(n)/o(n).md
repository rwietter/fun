# O(n)

A complexidade assintótica O(n) é uma função que cresce linearmente com o tamanho da entrada. Ou seja, se N é 5 então a complexidade é 5. Se N é 10 então a complexidade é 10. Se N é 1000 então a complexidade é 1000.

No melhor caso, onde a entrada é um array vazio ou com um único elemento, o algoritmo executará em tempo constante O(1). No pior caso, onde a entrada é um array com N elementos, o algoritmo executará em tempo linear O(n).

```js
function sum(arr) { // O(1)
  let sum = 0; // O(1)
  for (let i = 0; i < arr.length; i++) { // O(n)
    sum += arr[i]; // O(1)
  }
  return sum; // O(1)
}
```

![O(n)](./assets/linear.png)