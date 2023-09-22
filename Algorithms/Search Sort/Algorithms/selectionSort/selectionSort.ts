
const selectionSort = (arr: number[], size: number) => {

  const tuple: [number, number, number, number] = [0, 0, 0, 0]
  let [i, j, menorIndex, temp] = tuple;

  for (i = 0; i < size - 1; i++){
    menorIndex = i;

    for (j = i; j < size; j++){
      if (arr[j] < arr[menorIndex]) {
        menorIndex = j;
      }
    }
    
    temp = arr[menorIndex];
    arr[menorIndex] = arr[i];
    arr[i] = temp;
  }
  print(arr);
}

function print(arr: number[]) {
  arr.forEach(el => {
    console.log(el)
  })
}

(() => {
  const arr: number[] = [1, 4, 6, 8, 3, 1, 4, 56];
  const size: number = arr.length;
  selectionSort(arr, size);
})()
