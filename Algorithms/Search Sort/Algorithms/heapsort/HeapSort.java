public class HeapSort {
  public static void main(String[] args) {
    int arr[] = { 3, 64, 2, 12, 5 };
    int len = arr.length;
    heapsort(arr, len);
    for (int i : arr) {
      System.out.println(" " + i);
    }
  }

  static void heapsort(int arr[], int len) {
    // build max-heap
    for (int i = len / 2 - 1; i >= 0; i--) {
      heapfy(arr, len, i);
    }
    // heapsort
    for (int i = len - 1; i >= 0; i--) {
      int temp = arr[0];
      arr[0] = arr[i];
      arr[i] = temp;
      heapfy(arr, i, 0); // heapfy root element
    }
  }

  static void heapfy(int arr[], int len, int i) {
    int maior = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < len && arr[left] > arr[maior]) {
      maior = left;
    }
    if (right < maior && arr[right] > arr[maior]) {
      maior = right;
    }
    if (maior != i) {
      int temp = arr[i];
      arr[i] = arr[maior];
      arr[maior] = temp;
      heapfy(arr, len, maior);
    }
  }
}
