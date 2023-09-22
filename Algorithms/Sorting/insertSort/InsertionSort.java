public class InsertionSort {
  public static void main(String[] args) {
    int[] array = { 9, 14, 3, 2, 43, 11, 58, 22 };
    int size = array.length;
    ArraySorting.setInsertion(array, size);
    for (int i : array) {
      System.out.print(i + " ");
    }
  }
}

class ArraySorting {
  public static void setInsertion(int[] sort, int size) {
    int i = 0;
    while (i < size) {
      int key = sort[i];
      int j = i - 1;
      while ((j >= 0) && (sort[j] > key)) {
        sort[j + 1] = sort[j];
        j--;
      }
      sort[j + 1] = key;
      i++;
    }
  }
}
