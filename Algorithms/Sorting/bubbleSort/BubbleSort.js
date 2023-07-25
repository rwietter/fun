const print = arr => {
  arr.forEach(el => {
    console.log(el);
  })
}

const bubbleSort = (arr, size) => {
  let [i, j, aux] = [0, 0, 0];
  for (i = size - 1; i > 0; i--){
    for (j = 0; j < i; j++){
      if (arr[j] > arr[j + 1]) {
        aux = arr[j];
        arr[j] = arr[j + 1]
        arr[j + 1] = aux; 
      }
    }
  }
  print(arr);
}

(function () {
  let arr = [5, 6, 9, 1, 2];
  const size = arr.length;
  bubbleSort(arr, size);
})()
