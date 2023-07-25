(function () {
  let arr: Array<number> = [5, 6, 9, 1, 2];
  const size = arr.length;
  bubbleSort(arr, size);
})()

function bubbleSort(arr: number[], size: number) {
  
  let tuple: [number, number, number] = [0, 0, 0];
  let [i, j, auxiliar] = tuple;

  for (i = size - 1; i > 0; i--){
    for (j = 0; j < i; j++){
      if (arr[j] > arr[j + 1]) {
        auxiliar = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = auxiliar;
      }
    }
  }
  print(arr);
}

function print(arr: Array<number>) {
  arr.forEach(el => {
    console.log(el)
  })
}
