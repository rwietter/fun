(function () {
  let arr = [1, 6, 8, 4, 2];
  sort(arr, arr.length);
})()

function sort(arr, size) {
  let i = 0;
  while (i < size) {
    let key = arr[i];
    let j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j]
      j--;
    }
    arr[j + 1] = key;
    i++;
  }
  print(arr);
}

function print(arr) {
  arr.forEach(el => {
    console.log(el);
  })
}
