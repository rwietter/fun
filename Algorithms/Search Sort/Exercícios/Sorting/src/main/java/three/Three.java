package three;

import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Three {
  public static void main(String[] args) throws Exception {

    FileWriter arq = new FileWriter("C:\\tabuada.txt");
    PrintWriter gravarArq = new PrintWriter(arq);

    int arr[] = { 99, 88, 77, 46 };
    int size = arr.length;
    bubbleSort(arr, size);
    for (int i : arr) {
      gravarArq.println(i + " ");
    }
    gravarArq.close();
  }

  public static void insertionSort(int[] arr, int size) {
    // int firstIndex = 0, currentIndex = 0, key = 0;
  }

  public static void selectionSort(int[] arr, int size) {
    // int firstIndex = 0, secondIndex = 0, aux = 0, minIndex = 0;
  }

  public static void bubbleSort(int[] arr, int size) {
    int firstIndex, secondIndex, aux;
    for (firstIndex = size - 1; firstIndex > 0; firstIndex--) {
      boolean swapped = true;
      for (secondIndex = 0; secondIndex < firstIndex; secondIndex++) {
        if (arr[firstIndex] < arr[secondIndex]) {
          aux = arr[firstIndex];
          arr[firstIndex] = arr[secondIndex];
          arr[secondIndex] = aux;
          swapped = false;
        }
      }
      if (swapped == true) {
        break;
      }
    }
  }
}
