import Radixsort from "./Radixsort";
import MaxValue from "./MaxValue";

export default class App {
  private array: number[] = [55, 3, 77, 4, 4, 2, 55, 0, 1, 3, 46, 7, 8];
  private length: number = this.array.length;
  private maxValueArray: number = 0;

  getMaxValue(unsortedArray: number[]) {
    const maxValue = new MaxValue();
    this.maxValueArray = maxValue.getMaxValue(unsortedArray);
    return this.maxValueArray
  }

  radixSort() {
    if (!this.maxValueArray) return;
    const rdx = new Radixsort(
      this.array,
      this.length,
      this.maxValueArray,
    );
    rdx.radixSort();
  }

  getArraySorted() {
    console.log(this.array);
  }

  getArrayUnsorted() {
    return this.array;
  }

  printArray() {
    console.log(this.array);
  }
}

const app = new App();

app.getMaxValue(app.getArrayUnsorted());
app.radixSort();
app.printArray();
