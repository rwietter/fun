O algoritmo de Fibonacci é uma sequência matemática bem conhecida em que cada número é a soma dos dois números anteriores. A sequência começa com os números 0 e 1, e os próximos números são calculados somando os dois números anteriores. A sequência de Fibonacci se parece com isso: 0, 1, 1, 2, 3, 5, 8, 13, 21, etc...

Para explicar como funciona o algoritmo de Fibonacci e mostrar um teste de mesa, vamos calcular os primeiros 10 números da sequência.

1. Inicialmente, temos os números iniciais: a = 0 e b = 1.
2. O próximo número é a soma de a e b: c = a + b.
3. Atualizamos os valores de a e b para o próximo cálculo: a = b e b = c.
4. Repetimos os passos 2 e 3 até obtermos os primeiros 10 números da sequência.

|Iteração|a (atual)|b (próximo)|c (soma)|Sequência de Fibonacci|
|---|---|---|---|---|
|Início|0|1|-|0, 1|
|1|1|1|1|0, 1, 1|
|2|1|2|2|0, 1, 1, 2|
|3|2|3|3|0, 1, 1, 2, 3|
|4|3|5|5|0, 1, 1, 2, 3, 5|
|5|5|8|8|0, 1, 1, 2, 3, 5, 8|
|6|8|13|13|0, 1, 1, 2, 3, 5, 8, 13|
|7|13|21|21|0, 1, 1, 2, 3, 5, 8, 13, 21|
|8|21|34|34|0, 1, 1, 2, 3, 5, 8, 13, 21, 34|
|9|34|55|55|0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55|

```js
const fibo = (actual, next, n) => {
  while(n > 0) {
    [actual, next] = [next, actual + next]
    n--
  }
  return next
}

fibo(0, 1, 7)
```

Fibonacci com Generators.

```js
function* fibonacciGenerator(a = 0, b = 1) {
  while (true) {
    yield a;
    [a, b] = [b, a + b];
  }
}

const fibonacciIterator = fibonacciGenerator();

for (let i = 0; i < n; i++) {
  console.log(fibonacciIterator.next().value);
}
```

Fibonacci com Memoization.

```js
function fibo(n, memo = {}) {
	if (n <= 1) return n;
	
	if (memo[n]) return memo[n];
	
	memo[n] = fibo(n - 1, memo) + fibo(n - 2, memo);
	
	return memo[n];
}
```
