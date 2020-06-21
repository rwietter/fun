const errorsMessages = [
  { zip_code: { id: 1, message: "Cep incorreto" } },
  { address: { id: 2, message: "Endereço incorreto" } },
  { number: { id: 3, message: "Número incorreto" } },
  { test: { id: 4, message: "Identificação do MEC" } },
  { resources: { id: 5, message: "Tipos de recursos" } },
  { teste: { id: 6, message: "Hello" } },
];

const typeErrors = ["number", "resources", "zip_code"];

const includesObject = () => {
  let newErrors = [];
  errorsMessages.map((object, index) => {
    let objectKey = Object.keys(errorsMessages[index]);
    typeErrors.filter((error) =>
      error.includes(objectKey) ? newErrors.push(object) : null
    );
  }, []);
  return newErrors;
};

const pushError = () => {
  const errorMessage = [];
  includesObject().forEach((element, index) => {
    const nameErrorMessage = Object.keys(element);
    errorMessage.push(element[nameErrorMessage]);
  });
  return errorMessage;
};

console.log(pushError());


/*
const pushError = () => {
  const errorMessage = [];
  includesObject().forEach((element, index) => {
    errorMessage.push(element);
  });
  return errorMessage;
};
*/


/*
if error not includes in array, so insert this errors

function includesObject() {
  let arr = []
  errorsMessages.map((el, index) => {
    let objectKey = Object.keys(errorsMessages[index]);
    if (!errors.includes(objectKey[0])) {
      arr.push(objectKey)
      return;
    }
    return;
  }, [])
  const newArr = arr.map(el => el[0])
  return [...errors, ...newArr];
}
*/
