const Countingsort = (array, len, place, maxValue) => {
  const output = [];
  const count = [];

  for (let i = 0; i < maxValue; ++i){
    count[i] = 0;
  }

  for (let i = 0; i < len; i++){
    let index = Math.trunc((array[i] / place) % 10);
    count[index]++;
  }

  for (let i = 1; i < 10; i++){
    count[i] += count[i - 1];
  }

  for (let i = len - 1; i >= 0; i--){
    let index = Math.trunc((array[i] / place) % 10);
    output[count[index] - 1] = array[i];
    count[index]--;
  }

  for (let i = 0; i < len; i++){
    array[i] = output[i];
  }
  return array;
}

module.exports = Countingsort;
