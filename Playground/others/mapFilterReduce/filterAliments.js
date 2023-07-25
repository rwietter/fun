let estoque = ["maca", "uva", "morango"];
let items = ["uva", "maca", "pera", "goiaba"];

let hasItem = estoque.map((el) => {
	return items.includes(el) ? el : '';
});

console.log(hasItem);
