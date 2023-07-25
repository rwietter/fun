public class BubbleSort {
  public static void main(String args[]) {
    int arr[] = { 5, 8, 9, 3, 2, 66, 88, 1, 2 };
    int len = arr.length;
    bubbleSort(arr, len);
    for (int i : arr) {
      System.out.println(i + " ");
    }
  }

  static void bubbleSort(int[] arr, int len) {
    int i, j, temp = 0;
    for (i = len - 1; i > 0; i--) {
      for (j = 0; j < i; j++) {
        if (arr[j] > arr[j + 1]) {
          temp = arr[j];
          arr[j] = arr[j + 1];
          arr[j + 1] = temp;
        }
      }
    }
  }
}
