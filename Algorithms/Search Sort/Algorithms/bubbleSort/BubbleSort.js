const print = arr => {
  arr.forEach(el => {
    console.log(el);
  })
}

const bubbleSort = (arr, size) => {
  let [i, j, aux] = [0, 0, 0];
  for (i = 0; i < parseInt(arr.length / 2); i++){
      if (arr[i] > arr[i + 1]) {
        aux = arr[i];
        arr[i] = arr[i + 1]
        arr[i + 1] = aux; 
      }
    }
  print(arr);
}


// Memória = 5 + 5(n) => complexidade de espaço
// CPU 4 + (3 * 5(n)) => complexidade de tempo

// identificar a maior complexidade de n, descarta-se operações menos relevantes
// A ideia é avaliar como a complexidade aumenta de acordo com a entrada de dados do algoritmo

(function () {
  let arr = [5, 6, 9, 1, 2];
  const size = arr.length;
  bubbleSort(arr, size);
})()
