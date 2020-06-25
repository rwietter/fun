let url = "primeiro.segundo.meudominio.com.br";

let rgxcp = /^(\w+).(\w+).(\w*.com.br)$/;
let match = url.match(rgxcp)!;

console.log(`${match[1]}.${match[3]}`); // primeiro.meudominio.com.br

console.log(`${match[2]}`); // segundo
