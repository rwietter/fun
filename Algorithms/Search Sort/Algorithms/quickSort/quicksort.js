function index() {
  let arr = [6, 3, 67, 2, 5, 234];
  let len = arr.length;
  quick(arr, 0, len);
  arr.forEach(el => console.log(el));
}

function quick(arr, baixo, alto) {
  if (baixo < alto) {
    let pi = quickPartition(arr, baixo, alto);
    quick(arr, baixo, pi - 1);
    quick(arr, pi + 1, alto);
  }
}

function quickPartition(arr, baixo, alto) {
  let pivot = arr[alto];
  let i = baixo - 1;
  for (let j = baixo; j < alto; j++){
    if (arr[j] < pivot) {
      i++;
      let temp = arr[i];
      arr[i] = arr[j]
      arr[j] = temp;
    }
  }
  i++;
  let temp = arr[i];
  arr[i] = arr[alto];
  arr[alto] = temp;
  i--;
  return (i + 1);
}
index();
