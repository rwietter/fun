import MaxValue from '../MaxValue'
import App from '../App';
import Radixsort from '../Radixsort';

describe('TypeScript Radix Sort', () => {
  test('Max Value of array should return 774', () => {
    const max = new MaxValue();
    const arr = [1, 4, 774, 3, 2, 5, 77, 2, 3];
    
    const expected = 774;
    expect(max.getMaxValue(arr)).toBe(expected);
  });

  test('Radix Sort should returns array sorted [1, 2, 2, 3, 3, 4, 5, 77, 774]', () => {
    const app = new App();

    const arr = [1, 4, 774, 3, 2, 5, 77, 2, 3];
    const len = arr.length;

    const max = app.getMaxValue(arr);

    const rdx = new Radixsort(arr, len, max);
    app.radixSort();

    const expected: number[] = [1, 2, 2, 3, 3, 4, 5, 77, 774];

    expect(rdx.radixSort()).toMatchObject(expected);
  });
});
