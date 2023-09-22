public class BubbleSort {
  public static void main(String args[]) {
    int arr[] = { 5, 8, 9, 3, 2, 66, 88, 1, 2 };
    int arr_size = arr.length;
    BubleSortingAlgorithm bubble = new BubleSortingAlgorithm();
    bubble.orderBubbleSort(arr, arr_size);
    for (int i : arr) {
      System.out.println(i + " ");
    }
  }
}

class BubleSortingAlgorithm {
  public void orderBubbleSort(int[] arr, int size) {
    int i, j, auxiliar = 0;
    for (i = size - 1; i > 0; i--) {
      for (j = 0; j < i; j++) {
        if (arr[j] > arr[j + 1]) {
          auxiliar = arr[j];
          arr[j] = arr[j + 1];
          arr[j + 1] = auxiliar;
        }
      }
    }
  }
}
