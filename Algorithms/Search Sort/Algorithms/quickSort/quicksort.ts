function main(): any {
  let arr: number[] = [8, 4, 2, 6, 8, 21, 5];
  let len: number = arr.length;
  quickSort(arr, 0, len - 1);
  arr.forEach(el => console.log(el));
}

function quickPartition(arr: number[], baixo: number, alto: number): number {
  let pivot: number = arr[alto];
  let i: number = baixo - 1;
  for (let j: number = baixo; j < alto; j++){
    if (arr[j] < pivot) {
      i++;
      let temp: number = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  let temp: number = arr[i + 1];
  arr[i + 1] = arr[alto];
  arr[alto] = temp
  return (i + 1);
}

function quickSort(arr: number[], baixo: number, alto: number): any {
  if (baixo < alto) {
    let pi: number = quickPartition(arr, baixo, alto);
    quickSort(arr, baixo, pi - 1);
    quickSort(arr, pi + 1, alto);
  }
}
main();
