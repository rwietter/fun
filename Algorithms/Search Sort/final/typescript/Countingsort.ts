export default class CountingSort {
  private arr: number[];
  private len: number;
  private max: number;

  constructor(arr: number[], len: number, max: number) {
    this.arr = arr;
    this.len = len;
    this.max = max;
  }

  countingSort(place: number) {
    let output: number[] = [this.max + 1];

    let count: number[] = [this.max + 1];

    for (let i = 0; i < this.max; ++i) {
      count[i] = 0;
    }

    for (let i = 0; i < this.len; i++) {
      let index: number = Math.trunc((this.arr[i] / place) % 10);
      count[index]++;
    }

    for (let i = 1; i < 10; i++) {
      count[i] += count[i - 1];
    }

    for (let i = this.len - 1; i >= 0; i--) {
      let index: number = Math.trunc((this.arr[i] / place) % 10);
      output[count[index] - 1] = this.arr[i];
      count[index]--;
    }

    for (let i = 0; i < this.len; i++) {
      this.arr[i] = output[i];
    }
    return this.arr;
  }
}
