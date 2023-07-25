function param(num1) {
	return (num2) => {
		return num1 * num2;
	};
}

const par = param(4);
console.log(par(2));

// ----------------

let arr = [1, 5, 8, 5, 3, 5];

let filtered = arr
	.map((el, index) => el + index)
	.filter((e) => e >= 10)
	.reduce((element, index) => element + index);

console.log(filtered);
