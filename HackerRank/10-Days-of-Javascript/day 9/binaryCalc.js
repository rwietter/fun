const buttons = document.querySelectorAll('button');
const response = document.querySelector('#res');
const toBtnArray = Array.from(buttons);

const hasMatch = (string) => (mask) => string.match(mask);

const regex = {
  number: /\d+/g,
  _alphanumeric: /(\W)/g,
}

let $result = '';

const binaryCalc = () => {
  const input = $result;
  
  const [left, right] = hasMatch(input)(regex['number']);
  const [operator] = hasMatch(input)(regex['_alphanumeric']);
  const formula = parseInt(left, 2) + operator + parseInt(right, 2);

  let data = eval(formula).toString(2);
  return data;
}

const listenerBtns = (event) => {
  const value = event.target.value.toLowerCase();
  if (value === 'c') {
    $result = '';
  } else if (value === '=') {
    const fromBinary = binaryCalc();
    $result = fromBinary;
  } else {
    $result += value;
  }
  response.innerHTML = $result;
}

toBtnArray.map((elem, idx) => {
  elem.addEventListener('click', listenerBtns);
})
