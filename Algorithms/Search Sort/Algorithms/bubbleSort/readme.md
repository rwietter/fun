# Buble sort

<p align="center">
  <img src="https://github.com/rwietter/information-systems-ufsm/blob/master/search-and-sort-date/Algorithms/bubbleSort/bubblesort.png">
</p>

---

__Bubble sort e um algoritmo que compara elementos adjacentes e swaps de suas posições__

__A ideia é percorrer o vetor diversas vezes, e a cada passagem fazer flutuar para o topo o maior elemento da sequência__

__Simples de ser implementado__

__Lento para vetores grandes__

__In-place (Não necessita de vetor auxiliar)__

__Não estável (Elementos iguais são trocados de posição)__

__Adaptativo: dependendo da entrada, pode ser mais rápido__

__No melhor caso será O(n) e no pior será O(n2)__

---

1. A partir do primeiro índice, compara-se o primeiro e o segundo elemento. Se o primeiro for maior que o segundo, eles são trocados
2. Comparar o segundo com o terceiro elemento, se o segundo for maior que o terceiro, troca-se eles de posição, e assim por diante
3. A troca se repete até que os elementos da esquerda forem menor que os elementos da direita

---

### Pseudo código

```text
bubbleSort(matriz)
  para i <- 1 para indexOfLastUnsortedElement-1
  se leftElement > rightElement
  swap leftElement e rightElement
final bubbleSort
```

---

### Bubble sort algorithm

```java
public void orderBubbleSort(int[] arr, int size) {
  int i, j, auxiliar = 0;
  for (i = size - 1; i > 0; i--) {
    for (j = 0; j < i; j++) {

      int leftElement = arr[j];
      int rightElement = arr[j+1];

      if (leftElement > rightElement) {
        auxiliar = leftElement;
        leftElement = rightElement;
        arr[j + 2] = auxiliar;
      }
    }
  }
}
```

---

### Complexidade

#### Pior caso: O(n²)

__No pior caso a complexidade do algoritmo é O(n²): Loops(n*n = n²)__

---

#### Melhor caso: O(n)

__No melhor caso, o array já está ordenado, não sendo necessário a execução do loop interno__

---

#### Caso médio: O(n²)

__No caso médio, o array já está ordenado em partes__

---

#### Complexidade de espaço O(1)

__A complexidade de espaço é O(1), pois é utilizado uma variável auxiliar para armazenar o menor valor a cada loop__
