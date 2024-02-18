class SelectionSort {
  public static void main(String args[]) {
    int[] arr = { 1, 7, 9, 4, 2, 4 };
    int len = arr.length;
    selectionSort(arr, len);
    for (int i : arr) {
      System.out.println(i + " ");
    }
  }

  public static void selectionSort(int[] arr, int len) {
    int i = 0, j, lowIdx = 0, temp = 0;
    for (i = 0; i < len - 1; i++) {
      lowIdx = i;
      for (j = i; j < len; j++) {
        if (arr[j] < arr[lowIdx]) {
          lowIdx = j;
        }
      }
      temp = arr[lowIdx];
      arr[lowIdx] = arr[i];
      arr[i] = temp;
    }
  }
}
