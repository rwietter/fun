
(function () {
  const arr: Array<number> = [5, 7, 8, 3, 1, 9];
  let size: number = arr.length;
  insertionSort(arr, size);
})()

function insertionSort(array: number[], size: number) {
  let index: number = 0;
  while (index < size) {
    let nextValue: number = array[index];
    let j: number = index - 1;
    while (j >= 0 && array[j] > nextValue) {
      array[j + 1] = array[j];
      j--;
    }
    array[j + 1] = nextValue;
    ++index;
  }
  print(array, size);
}


function print(array: number[], size: number) {
  array.forEach(el => {
    console.log(el)
  });
}
