import java.util.Random;

public class Main {
  public static void main(String[] args) {
    int[] v = new int[10];

    insereValores(v);

    int n = v.length;
    insertionSort(v, n);

    System.out.println("\n===== Vetor Ordenado =====");
    imprimeValores(v);
  }

  static void insereValores(int[] v) {
    Random gerador = randomValues();
    int n = v.length;
    for (int i = 0; i < n; i++) {
      v[i] = gerador.nextInt(100);
    }
  }

  static void imprimeValores(int[] v) {
    int n = v.length;
    for (int i = 0; i < n; i++) {
      System.out.printf("[%d] = %2d\n", i, v[i]);
    }
  }

  static Random randomValues() {
    Random gerador = new Random();
    return gerador;
  }

  static void insertionSort(int[] arraySort, int arrSize) {
    for (int i = 1; i < arrSize; ++i) {
      int key = arraySort[i];
      int j = i - 1;
      while (j >= 0 && arraySort[j] > key) {
        arraySort[j + 1] = arraySort[j];
        j = j - 1;
      }
      arraySort[j + 1] = key;
    }
  }
}
