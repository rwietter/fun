const MaxValue = require('./maxvalue.js');
const Countingsort = require('./countingsort.js');

const Radix = (array, len) => {
  const maxValue = MaxValue(array, len);
  let place = 1;
  let sorted = [];
  for (place; Math.trunc(maxValue / place) > 0; place *= 10) {
    sorted = Countingsort(array, len, place, maxValue);
  }
  return sorted;
}

module.exports = Radix;
