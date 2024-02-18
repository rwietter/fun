(() => {
  const arr = [6, 3, 3];
  const size = arr.length;
  select_sort(arr, size);
})()

function selectionSortAlgorithm(arr, size) {
  let [i, j, menorIndex, temp] = [0, 0, 0, 0];

  for (i = 0; i < size - 1; i++){
    menorIndex = i;
    
    for (j = i; j < size; j++){
      if (arr[j] < arr[menorIndex]) {
        menorIndex = j;
      }
    }
    temp = arr[menorIndex];
    arr[menorIndex] = arr[i]
    arr[i] = temp;
  }
  print(arr);
}

function print(arr) {
  arr.forEach(el => {
    console.log(el);
  })
}

function select_sort(arr, size) {
  let [i, j, temp, minIndex] = [0, 0, 0, 0]
  for (i = 0; i < size - 1; i++){
    minIndex = i
    for (j = i; j < size; j++){
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    // Optimized algorithm, no change repeat values
    if (arr[minIndex] < arr[i]) {
      temp = arr[minIndex];
      arr[minIndex] = arr[i];
      arr[i] = temp;
    }
  }
  print(arr);
}
