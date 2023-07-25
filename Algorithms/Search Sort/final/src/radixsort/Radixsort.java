package src.radixsort;

import src.countingsort.CountingSort;

public class Radixsort {
  CountingSort cs = new CountingSort();

  // obtém o maior elemento do array
  int getMax(int data[], int len) {
    int maxValue = data[0];
    for (int idx = 1; idx < len; idx++) {
      if (data[idx] > maxValue)
        maxValue = data[idx];
    }
    return maxValue;
  }

  // radixSort algorithm
  public void radixSort(int data[], int len) {
    int maxValue = getMax(data, len);
    for (int place = 1; maxValue / place > 0; place *= 10) {
      this.cs.countingSort(data, len, place, maxValue);
    }
  }
}
