
public class Shellsort {
  public static void main(String args[]) {
    int[] arr = { 4, 6, 8, 5, 33, 1 };
    int len = arr.length;
    shellSort(arr, len);
    for (int i : arr) {
      System.out.println(i + " ");
    }
  }

  static void ShellSort(int[] arr, int len) {
    for (int gap = len / 2; gap > 0; gap /= 2) {
      for (int i = gap; i < len; i += 1) {
        int temp = arr[i];
        int j;
        for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
          arr[j] = arr[j - gap];
        }
        arr[j] = temp;
      }
    }
  }

  public static void shellSort(int[] arr, int size) {
    int divider = 1, j = 0;
    while (divider < size) {
      divider = divider * 3 + 1;
    }
    divider /= 3;
    int aux;
    while (divider > 0) {
      for (int i = divider; i < size; i++) {
        aux = arr[i];
        j = i;
        while (j >= divider && arr[j - divider] > aux) {
          arr[j] = arr[j - divider];
          j -= divider;
        }
        arr[j] = aux;
      }
      divider /= 2;
    }
  }
}
