# Big-O Notation

The Big-O notation allows us to show a scenario where the algorithm is performing at its worst. It is used to compare the performance of different algorithms. So, we can compare the performance of different algorithms and choose the best one for a given scenario.

1. O(1) - Constant Time
2. O(log n) - Logarithmic Time
3. O(n) - Linear Time
4. O(n log n) - Log Polynomial Time
5. O(n^2) - Quadratic Time
6. O(n^3) - Cubic Time
7. O(2^n) - Exponential Time
8. O(n!) - Factorial Time
9. O(nk) - Polynomial Time
10. O(n+k) - Linear Time

### O(1) - Constant Time

The algorithm takes the same amount of time to complete, regardless of the size of the input. The algorithm does not depend on the size of the input.

```js
function sum(arr) {
  return arr[0] + arr[1];
}
```

### O(log n) - Logarithmic Time

The array is divided in half each time. The algorithm takes the same amount of time to complete, regardless of the size of the input. The algorithm does not depend on the size of the input.

```js
function sum(arr) {
  let sum = 0;
  for (let i = 0; i < arr.length; i = i * 2) {
    sum += arr[i];
  }
  return sum;
}
```

### O(n) - Linear Time

The operation depends on the size of the input. The algorithm takes more time to complete as the size of the input increases.

```js
function sum(arr) {
  let sum = 0;
  for (let i = 0; i < arr.length; i++) {
    sum += arr[i];
  }
  return sum;
}
```

### O(n log n) - Log Polynomial Time

The algorithm takes more time to complete as the size of the input increases.

```js
function sum(arr) {
  let sum = 0;
  for (let i = 0; i < arr.length; i++) {
    for (let j = 0; j < arr.length; j = j * 2) {
      sum += arr[i] + arr[j];
    }
  }
  return sum;
}
```

### O(n^2) - Quadratic Time


```js
function sum(arr) {
  let sum = 0;
  for (let i = 0; i < arr.length; i++) {
    for (let j = 0; j < arr.length; j++) {
      sum += arr[i] + arr[j];
    }
  }
  return sum;
}
```

### O(n^3) - Cubic Time

```js
function sum(arr) {
  let sum = 0;
  for (let i = 0; i < arr.length; i++) {
    for (let j = 0; j < arr.length; j++) {
      for (let k = 0; k < arr.length; k++) {
        sum += arr[i] + arr[j] + arr[k];
      }
    }
  }
  return sum;
}
```

### O(2^n) - Exponential Time


### O(n!) - Factorial Time

```js
function factorial(n) {
  if (n === 0) {
    return 1;
  }
  return n * factorial(n - 1);
}
```

### O(n^n) - Exponential Time


### O(nk) - Polynomial Time

O(nk) representa uma complexidade de tempo polinomial, onde o tempo de execução do algoritmo cresce em função de n e k. Isto significa que o desempenho do algoritmo depende tanto do tamanho da entrada (n) quanto da magnitude de algum outro parâmetro (k). Por exemplo, um algoritmo que ordena um array 2D usando loops aninhados teria uma complexidade de tempo de O(n^2), onde n é o comprimento de cada dimensão do array.

```js
for( i=0; i<n; i++ ) { // O(n)
  for( j=0; j<k; j++ ) { // O(k)
    // do something
  }
}

// O(nk) = O(n) * O(k)
```

### O(n+k) - Linear Time

O(n+k), por outro lado, representa uma complexidade de tempo linear, onde o tempo de execução do algoritmo cresce apenas em função da soma de n e k. Isto significa que o desempenho do algoritmo depende principalmente do tamanho da entrada (n) e não é significativamente afetado pela magnitude de qualquer outro parâmetro (k). Por exemplo, um algoritmo que ordena um array de números e depois conta o número de números inteiros até mesmo no array teria uma complexidade de tempo de O(n+k), onde n é o comprimento do array e k é o número de números inteiros até mesmo no array.

```js
for(i = 0; i < n; i++) { // O(n)
  // do something
}

for(i = 0; i < k; i++) { // O(k)
  // do something
}

// O(n+k) = O(n) + O(k)
```