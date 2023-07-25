package sort;
public class App {
  public static void main(String[] args) {
    int[] arr = { 3, 4, 9, 2, 5, 8, 2, 1, 7, 4, 6, 2, 9, 8, 5, 1 };
    int arrSize = arr.length;
    // insertionSort(arr, arrSize);
    // bubbleSort(arr, arrSize);
    selectionSort(arr, arrSize);
    for (int i : arr) {
      System.out.println(" " + i);
    }
  }

  public static void insertionSort(int[] arr, int size) {
    int i = 0, j = 0, aux = 0;
    while (i < size) {
      aux = arr[i];
      j = i - 1;
      while (j >= 0 && arr[j] > aux) {
        arr[j + 1] = arr[j];
        j--;
      }
      arr[j + 1] = aux;
      i++;
    }
  }

  public static void bubbleSort(int[] arr, int size) {
    int i, j, aux;
    for (i = size - 1; i > 0; i--) {
      for (j = 0; j < i; j++) {
        if (arr[j] > arr[j + 1]) {
          aux = arr[j];
          arr[j] = arr[j + 1];
          arr[j + 1] = aux;
        }
      }
    }
  }

  public static void selectionSort(int arr[], int size) {
    int i, j, aux, menorIndex;
    for (i = 0; i < size - 1; i++) {
      menorIndex = i;
      for (j = i; j < size; j++) {
        if (arr[menorIndex] > arr[j]) {
          menorIndex = j;
        }
      }
      aux = arr[menorIndex];
      arr[menorIndex] = arr[i];
      arr[i] = aux;
    }
  }
}

/*
 * 2- Dada a sequência de números: 3 4 9 2 5 8 2 1 7 4 6 2 9 8 5 1, ordene-a em
 * ordem não decrescente segundo os seguintes algoritmos, apresentando a
 * sequência obtida após cada passo do algoritmo: a. MergeSort b. QuickSort c.
 * HeapSort
 */
