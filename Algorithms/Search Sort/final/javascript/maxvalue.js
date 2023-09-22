const MaxValue = (array, len) => {
  let max = array[0];
  array.filter((item) => item > max ? max = item : null);
  return max;
}

module.exports = MaxValue;
