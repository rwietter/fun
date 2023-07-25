# Insertion Sort

- A classificação por inserção é um algoritmo de classificação que coloca um elemento não classificado em seu local adequado em cada iteração.
- A Inserção por classificação funciona da seguinte forma, insere o segundo elemento e ordena ele, caso o terceiro elemento for menor que o primeiro elemento já classificado, o algoritmo irá reordenar desde o começo novamente.
Ex: [9, 5, 1] => [9, 9, 1] => [5, 9, 1] => [5, 9, 9] => [5, 1, 9] => [5, 5, 9] => [1, 5, 9]

1. Assumimos que o primeiro elemento já está classificado, vamos para o segundo.
2. Selecionamos um elemento não classificado
3. Se o elemento selecionado não é classificado e for maior que o que temos em uma variável, colocamos ele a direita, caso contrário a esquerda
4. Assim por diante com todos os elementos do array

---

1. Guardamos o elemento da frente em uma key
2. Se o primeiro elemento for maior do que a chave, a chave é colocada na frente do primeiro elemento

---

#### Pseudo-código

```text
insertionSort(matriz)
  marca primeiro elemento como classificados
  para cada elemento X não classificada
    'extrair' o elemento X
  para j <- lastSortedIndex a 0
    se o elemento de corrente j > X
      mover classificados elemento para a direita por 1
  quebra de ciclo e inserir X aqui
final insertionSort
```

---

```java
class ArraySorting {
  public static void setInsertion(int[] sort, int size) {
    int i = 0;
    while (i < size) {
      int key = sort[i]; // received element of comparation
      int j = i - 1;
      while ((j >= 0) && (sort[j] > key)) {
        sort[j + 1] = sort[j];
        j--; // decrement position for insertion element
      }
      sort[j + 1] = key;
      i++; // increment external loop
    }
  }
}
```

---

## COMPLEXIDADE

### Pior caso de complexidade

- No pior caso a complexidade será de O(n²)
- O Pior caso será ordenar uma estrutura de dados decrescente para crescente
- Nesse caso: ```nComparações = n*(n-1) ~ n2```

### Melhor caso de complexidade

- A complexidade linear ocorre quando o loop externo é iterado n vezes, enquanto o loop internet não é usado
  
### Caso médio de complexidade

- O caso médio de complexidade será O(n²)
- Esse caso acontece quando os elementos estão distribuídos de forma variada
