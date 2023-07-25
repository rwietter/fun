class SelectionSort {
  public static void main(String args[]) {
    int[] arr = { 1, 7, 9, 4, 2, 4 };
    int size = arr.length;
    selectionSort(arr, size);
    for (int i : arr) {
      System.out.println(i + " ");
    }
  }

  public static void selectionSort(int[] arr, int size) {
    int i, j, menorIndex, aux = 0;
    for (i = 0; i < size - 1; i++) {
      menorIndex = i;
      for (j = i; j < size; j++) {
        if (arr[j] < arr[menorIndex]) {
          menorIndex = j;
        }
      }
      aux = arr[menorIndex];
      arr[menorIndex] = arr[i];
      arr[i] = aux;
    }
  }
}
