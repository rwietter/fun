# Quicksort

__Abordagem: dividir e conquistar.__

__O array é dividido em dois sub-arrays que são chamados recursivamente para classificar os elementos independentemente.__

---

## Como funciona ?

1. Um elemento do array é escolhido como pivô, pode ser qualquer elemento.

```javascript
let array = {8, 7, 6, 1, 0, 9, 2};
let pivot = arr[6];
```

2. Os elementos menores que o pivô são colocados à esquerda e os elementos maiores que o pivô são colocados à direita dele.

```javascript
{1, 0, 2, 8, 7, 9, 6};
```

---

## Complexidade

__Pior caso:__ ocorre quando o pivot é um extremo, nesse caso será O(n²)

__Melhor caso:__ quando o elemento dinâmico é um intermediário, nesse caso será O(n * log n)

__Caso médio:__ quando o element dinâmico é próximo ao intermediário, nesse caso será O(n * log n)

__Complexidade de espaço:__ O(n * log n)
