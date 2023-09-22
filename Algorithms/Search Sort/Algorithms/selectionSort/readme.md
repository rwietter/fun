# Selection sort

<p align="center">
  <img src="https://github.com/rwietter/information-systems-ufsm/blob/master/search-and-sort-date/Algorithms/selectionSort/selection.PNG">
</p>

---

- __O Selection sort funciona selecionando o menor elemento da lista não-ordenada a cada iteração e coloca o elemento no começo da lista no seu devido lugar__

- __Seleciona o menor elemento e compara ele com os elementos restante até achar o menor da lista__

- __Refaz o processo até que a lista esteja ordenada__

- __Ex: [20, 12, 7, 5]: => [5, 12, 7, 20] => [5, 7, 12, 20]__

---

- __Passa sempre o menor valor do vetor para a primeira posição (ou o maior dependendo da ordem requerida), depois o de segundo menor valor para a segunda posição,e assim sucessivamente com os n-1 elementos restantes.__

- __Simples de ser implementado__

- __Lento para vetores grandes__

- __In-place (Não necessita de vetor auxiliar)__

- __Não estável (Elementos iguais são trocados de posição)__

- __Independente do caso, sempre será O(n2)__

---

#### Pseudo código

```
selectionSort(matriz, tamanho)
  repetir (tamanho - 1) vezes
    o primeiro conjunto não ordenado elemento, como o mínimo de
  para cada um dos elementos indiferenciados
    se o elemento < currentMinimum
    conjunto de elemento novo mínimo
  trocar o mínimo com a primeira posição não-ordenada
final selectionSort
```

---

#### Selection sort Algorithm

```java
public static void selectionSort(int[] arr, int size) {
  int i, j, menorIndex, aux = 0;
  for (i = 0; i < size - 1; i++) {
    menorIndex = i;
    for (j = i; j < size; j++) {
      if (arr[j] < arr[menorIndex]) {
        menorIndex = j;
      }
    }
    aux = arr[menorIndex];
    arr[menorIndex] = arr[i];
    arr[i] = aux;
  }
}
```

--- 

#### Complexidade

__A complexidade é O(n²): observando os dois loops: n*n = (n²)__

---

##### Tempo de complexidade

- __No pior caso:__
__A complexidade será O(n²), quando a ordenação é crescente mas os dados estão de forma decrescente__

- __No melhor caso:__
__A complexidade será O(n²), ocorre quando a estrutura já está classificada__

- __No caso médio:__
__A complexidade será O(n²), ocorre quando parte está ordenada e parte está desordenada__

---

##### Espaço de complexidade

__O espaço de complexidade será O(1) por conta tem uma variável temporária__
