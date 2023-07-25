const Radix = require("../radixsort.js");

describe('JavaScrit Radix Sort', () => {
  test('Radix should return array sorted [0, 0, 0, 1, 2, 48, 553, 835, 934, 2303, 4994949]', () => {
    const array = [835, 553, 48, 0, 0, 2303, 934, 4994949, 0, 1, 2];
    const len = array.length;

    const expected = [0, 0, 0, 1, 2, 48, 553, 835, 934, 2303, 4994949];
    expect(Radix(array, len)).toMatchObject(expected);
  });

  test('Radix should return array sorted [0, 0, 0, 0, 1, 2, 3, 3, 5, 6, 48, 49, 3828]', () => {
    const array = [48, 0, 0, 0, 0, 1, 2, 3, 5, 6, 3, 3828, 49];
    const len = array.length;

    const expected = [0, 0, 0, 0, 1, 2, 3, 3, 5, 6, 48, 49, 3828]
    expect(Radix(array, len)).toMatchObject(expected);
  });
});
