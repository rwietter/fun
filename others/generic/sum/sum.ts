let current = 1, sum = 0, total = 0;

for (let i = 0; i <= 9; i++) {
  current++;
  if (sum >= 1) sum += sum - 1;
  sum++;

  console.log(`${sum}/${current}`);
  total += sum / current;
}
console.log(total);

let numerador = 1, denominador = 2, somatorio = 0;
for (let i = 0; i < 10; i++) {
  somatorio += (numerador / denominador);
  numerador *= 2;
  denominador += 1;
}
console.log(somatorio);
