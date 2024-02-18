let arr = [1, 4, 6, 8, 2]

function name(start, end, arr) {
  if (start >= end) {
    return arr
  }
  let aux = arr[start];
  arr[start] = arr[end];
  arr[end] = aux;

  return name(start + 1, end - 1, arr)
}
console.log(name(0, 4, arr));
