# Shell sort

__Baseado no Insertion sort.__

__Separa os elementos um do outro e reduz sucessivamente o intervalo entre os elementos a serem classificado.__

__Os elementos em um intervalo de tempo específico são classificados. O intervalor entre os elementos é diminuído gradualmente com base em uma sequência usada.__

---

__Supondo que:__

```javascript
let arr = {9, 8, 3, 7, 5, 6, 4, 1}
let len = arr.lenght; // 8
let divider = len / 2; // 4
```

__Os valores situado no intervalo serão trocados, se necessário.__

__Index 0 comparado com index 4.__

__Se array[0] > array[4], então ele são trocados.__

__LOOP 1:__

```javascript
{9, 8, 3, 7, 5, 6, 4, 1} // original
{5, 8, 3, 7, 9, 6, 4, 1} // 9 > 5 // true
{5, 6, 3, 7, 9, 8, 4, 1} // 8 > 6 // true
{5, 6, 3, 7, 9, 8, 4, 1} // 3 > 4 // false
{5, 6, 3, 1, 9, 8, 4, 7} // 7 > 1 // true
```

__LOOP 2:__

```javascript
divider = 8 / 4; // 2

{3, 6, 5, 1, 9, 8, 4, 7} // 5 > 3 // true
{3, 1, 5, 6, 9, 8, 4, 7} // 6 > 1 // true
{3, 1, 5, 6, 9, 8, 4, 7} // 5 > 9 // false
{3, 1, 5, 6, 9, 8, 4, 7} // 6 > 8 // false
{3, 1, 5, 6, 4, 8, 9, 7} // 9 > 4 // true
{3, 1, 5, 6, 4, 7, 9, 8} // 8 > 7 // true
```

__LOOP 3:__

```javascript
divider = 8 / 8; // 1

{1, 3, 5, 6, 4, 7, 9, 8} // 3 > 1 // true
{1, 3, 5, 6, 4, 7, 9, 8} // 3 > 5 // false
{1, 3, 5, 6, 4, 7, 9, 8} // 5 > 6 // false
{1, 3, 5, 4, 6, 7, 9, 8} // 6 > 4 // true
{1, 3, 5, 4, 6, 7, 9, 8} // 6 > 7 // false
{1, 3, 5, 4, 6, 7, 9, 8} // 7 > 9 // false
{1, 3, 5, 4, 6, 7, 8, 9} // 9 > 8 // true
```

---

__Sequências que podem ser utilizadas no shell sort:__

```text
Sequência original da Shell: N/2 , N/4 , …, 1
Incrementos de Knuth: 1, 4, 13, …, (3k – 1) / 2
Incrementos de Sedgewick: 1, 8, 23, 77, 281, 1073, 4193, 16577...4j+1+ 3·2j+ 1
Incrementos de Hibbard: 1, 3, 7, 15, 31, 63, 127, 255, 511…
Incremento de Papernov e Stasevich: 1, 3, 5, 9, 17, 33, 65,...
Pratt: 1, 2, 3, 4, 6, 9, 8, 12, 18, 27, 16, 24, 36, 54, 81....
```

---

## Complexidade

__Pior caso de complexidade:__ O(n²)

__Melhor caso de complexidade:__ O(n * log n)

__Caso médio de complexidade:__ O(n * log n)

__Complexidade de espaço:__ O(1)
