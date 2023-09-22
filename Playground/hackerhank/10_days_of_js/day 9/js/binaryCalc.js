const buttons = document.querySelectorAll('button');
const response = document.querySelector('#res');
const btnList = Array.from(buttons);
let output = '';

const lowerCaseStr = (value) => value.toLowerCase();
const hasMatch = (string) => (mask) => string.match(mask);
const rgxTest = (string) => {
  const rgx = new RegExp(/(=|c)/);
  return rgx.test(string);
};

const regex = {
  number: /\d+/g,
  _alphanumeric: /(\W)/g,
}

const binaryCalc = () => {
  const input = output;
  
  const [leftValue, rightValue] = hasMatch(input)(regex['number']);
  const [operator] = hasMatch(input)(regex['_alphanumeric']);
  const formula = parseInt(leftValue, 2) + operator + parseInt(rightValue, 2)
  
  let data = eval(formula).toString(2);
  return data;
}

const isEqual = (input) => (op) => input === op;

const validade = [
  [(input) => isEqual(input)('c'), ''],
  [(input) => isEqual(input)('='), binaryCalc]
]

const sendOutput = (binary) => response.innerHTML = binary;

const getBinary = (input, result) => {
  const hasOperator = rgxTest(input);
  
  if (hasOperator) {
    const [_, args] = validade.find(([fn]) => fn(input));
    typeof args === 'function'
      ? output = args()
      : output = ''
  }
  return output;
}
const listeningOnClick = ({ target: { value } }) => {
  const input = lowerCaseStr(value);
  output += input;
  sendOutput(output);
  output = getBinary(input, output);
  return sendOutput(output);
}

btnList.map((element) => element.addEventListener('click', listeningOnClick));
