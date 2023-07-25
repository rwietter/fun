public class Mergesort {
  public static void merge(int arr[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[] = new int[n1];
    int M[] = new int[n2];

    for (int i = 0; i < n1; i++)
      L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
      M[j] = arr[q + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2) {
      if (L[i] <= M[j]) {
        arr[k] = L[i];
        i++;
      } else {
        arr[k] = M[j];
        j++;
      }
      k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1) {
      arr[k] = L[i];
      i++;
      k++;
    }

    while (j < n2) {
      arr[k] = M[j];
      j++;
      k++;
    }
  }

  static void mergesort(int arr[], int left, int right) {
    if (left < right) {
      int m = (left + right) / 2;
      mergesort(arr, left, m);
      mergesort(arr, m + 1, right);
      merge(arr, left, m, right);
    }
  }

  public static void main(String args[]) {
    int arr[] = { 6, 89, 5, 6, 2, 1, 8, 8, 5 };
    int len = arr.length;
    mergesort(arr, 0, len - 1);
    for (int i : arr) {
      System.out.println(" " + i);
    }
  }
}
