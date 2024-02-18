
public class Quicksort {

  public static int quickPartition(int[] arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
      if (arr[j] <= pivot) {
        i++;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
  }

  public static void quickSort(int[] arr, int low, int high) {
    if (low < high) {
      int pi = quickPartition(arr, low, high);
      quickSort(arr, low, pi - 1);
      quickSort(arr, pi + 1, high);
    }
  }

  public static void main(String[] args) {
    int[] arr = { 6, 48, 46, 87, 91, 36, 19, 57, 49, 14 };
    int len = arr.length;
    quickSort(arr, 0, len - 1);
    for (int i : arr) {
      System.out.println(i + " ");
    }
  }
}
