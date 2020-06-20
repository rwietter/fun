const errorsMessages = [
  { zip_code: { id: 1, message: 'Cep incorreto' } },
  { address: { id: 2, message: 'Endereço incorreto' } },
  { number: { id: 3, message: 'Número incorreto' } }
]

const errors = ['zip_code', 'address', 'number']
const erro = [];

errors.forEach((el, index) => {
  erro.push(errorsMessages[index][el])
})

console.log(erro);


// output
[
  { id: 1, message: 'Cep incorreto' },
  { id: 2, message: 'Endereço incorreto' },
  { id: 3, message: 'Número incorreto' }
]
