```js
function fibo(n, memo = {}) {
	if (n <= 1) return n;
	
	if (memo[n]) return memo[n];
	
	memo[n] = fibo(n - 1, memo) + fibo(n - 2, memo);
	
	return memo[n];
}
```


![fibo](fibo.png)

### References
- [Time Complexity of Memoization Fibonacci?](https://stackoverflow.com/questions/42617249/time-complexity-of-memoization-fibonacci)

