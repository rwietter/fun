public class InsertionSort {
  public static void main(String[] args) {
    int[] array = { 9, 5, 1 };
    int len = array.length;
    insertionSort(array, len);
    for (int i : array) {
      System.out.print(i + " ");
    }
  }

  static void insertionSort(int[] arr, int size) {
    int firstIdx = 0, currIdx = 0, aux = 0;
    while (firstIdx < size) {
      aux = arr[firstIdx];
      currIdx = firstIdx - 1;
      while (currIdx >= 0 && arr[currIdx] > aux) {
        arr[currIdx + 1] = arr[currIdx];
        currIdx--;
      }
      arr[currIdx + 1] = aux;
      firstIdx++;
    }
  }
}
