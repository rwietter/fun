const buttons = document.querySelectorAll('button');
const response = document.querySelector('#res');
const btnList = Array.from(buttons);
let resulted = '';

const SendOuput = (binary) => response.innerHTML = binary;
const lowerCaseStr = (value) => value.toLowerCase();
const hasMatch = (string) => (mask) => string.match(mask);

const regex = {
  number: /\d+/g,
  _alphanumeric: /(\W)/g,
}

const binaryCalc = (result) => {
  const input = result;
  
  const [left, right] = hasMatch(input)(regex['number']);
  const [operator] = hasMatch(input)(regex['_alphanumeric']);
  const formula = parseInt(left, 2) + operator + parseInt(right, 2);

  let data = eval(formula).toString(2);
  return data;
}

const isEqual = (input) => (op) => input === op;

const listeningOnClick = ({ target: { value } }) => {
  const input = lowerCaseStr(value);
  if (isEqual(input)('c')) {
    resulted = '';
  } else if (input === '=') {
    const fromBinary = binaryCalc();
    resulted = fromBinary;
  } else {
    resulted += input;
  }
  return SendOuput(resulted);
}

btnList.map((element) => element.addEventListener('click', listeningOnClick));
