import CountingSort from "./Countingsort.ts";

export default class RadixSort {
  private arr: number[];
  private len: number;
  private max: number;
  private newArraySorted: number[] = [];

  constructor(array: number[], length: number, maxValue: number) {
    this.arr = array;
    this.len = length;
    this.max = maxValue;
  }

  radixSort() {
    const cs = new CountingSort(this.arr, this.len, this.max);

    let place = 1;

    for (place; Math.trunc(this.max / place) > 0; place *= 10) {
      this.newArraySorted = cs.countingSort(place);
    }
    return this.newArraySorted;
  }
}
