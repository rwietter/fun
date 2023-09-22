# Algoritmos

<strong>REFERÊNCIA:</strong>

[Goalkicker - Algorithms Notes for Professionals book](https://books.goalkicker.com/AlgorithmsBook/)

---

<strong>Estável</strong>

<em>Um algoritmo de ordenação é estável se preservar a ordem relativa dos elementos iguais após a ordenação.</em>

<strong>Algoritmos estáveis</strong>

<ul>
  <li>Merge sort</li>
  <li>Insertion sort</li>
  <li>Radix sort</li>
  <li>Tim sort</li>
  <li>Bubble Sort</li>
</ul>

<strong>Algoritmos não-estáveis</strong>

<ul>
  <li>Heap sort</li>
  <li>Quick sort</li>
</ul>

---

<strong>In place</strong>

<em>Um algoritmo de classificação é In Place se classificar usando apenas memória auxiliar O(1) (sem contar o array que precisa ser ordenado).</em>

---

<strong>Best case complexity</strong>

<em>Um algoritmo de ordenação possui uma complexidade de O(T(n)) no melhor caso possível, se o tempo de execução for pelo menos T(n) para todas as entradas possíveis.</em>

---

<strong>Average case complexity</strong>

<em>Um algoritmo de ordenação possui uma complexidade média de tempo de processo de O(T(n)) em tempo de execução, calculando sobre todas as entradas possíveis, é T(n).</em>

---

<strong>Worst case complexity</strong>

<em>Um algoritmo de ordenação tem uma complexidade de pior caso de O(T (n)) se seu tempo de execução for no máximo T(n).</em>

---

### Bubble Sort

<strong>O BubbleSort compara cada par sucessivo de elementos em uma lista não ordenada e inverte os elementos se não eles estiverem em ordem.</strong>

```
{6,5,3,1,8,7,2,4}
{**5,6**,3,1,8,7,2,4} -- 5 < 6 -> swap
{5,**3,6**,1,8,7,2,4} -- 3 < 6 -> swap
{5,3,**1,6**,8,7,2,4} -- 1 < 6 -> swap
{5,3,1,**6,8**,7,2,4} -- 8 > 6 -> no swap
{5,3,1,6,**7,8**,2,4} -- 7 < 8 -> swap
{5,3,1,6,7,**2,8**,4} -- 2 < 8 -> swap
{5,3,1,6,7,2,**4,8**} -- 4 < 8 -> swap
```

<strong>Após uma iteração através da lista, temos {5,3,1,6,7,2,4,8}. O maior valor não ordenado no array (8 neste caso) sempre atingirá sua posição final. Assim, para ter certeza de que a lista está ordenada, devemos iterar n-1 vezes para listas de comprimento n.</strong>

<strong>O BubbleSort também é conhecido como Sinking Sort. É um algoritmo de classificação simples que passa repetidamente pela lista a ser ordenada, compara cada par de itens adjacentes e os troca se eles estiverem na ordem errada.</strong>

<img src="https://i.stack.imgur.com/SDHQM.jpg">

```java
public class BubbleSort {
  public static void main(String args[]) {
    int arr[] = { 5, 8, 9, 3, 2, 66, 88, 1, 2 };
    int len = arr.length;
    bubbleSort(arr, len);
    for (int i : arr) {
      System.out.println(i + " ");
    }
  }

  static void bubbleSort(int[] arr, int len) {
    int i, j, temp = 0;
    for (i = len - 1; i > 0; i--) {
      for (j = 0; j < i; j++) {
        if (arr[j] > arr[j + 1]) {
          temp = arr[j];
          arr[j] = arr[j + 1];
          arr[j + 1] = temp;
        }
      }
    }
  }
}
```

---

### Merge Sort

<strong>MergeSort é um algoritmo de dividir e conquistar. Ele divide a lista de entrada do comprimento <em>n</em> ao meio sucessivamente até que haja listas de tamanho 1. Em seguida, pares de listas são mesclados com o primeiro elemento menor entre o par de listas a serem adicionadas a cada etapa. Por meio de sucessivas fusões e através de comparações dos primeiros elementos, a lista é ordenada.</strong>

<img src="https://i.stack.imgur.com/Bs29u.png">

<strong>Complexidade de Tempo</strong>

<em>A complexidade de tempo em todos os casos é O(n log n)</em>

<strong>Complexidade de Espaço</strong>

<em>O(n)</em>

<strong>Paradigma</strong>

<em>Dividir e conquistar</em>

<strong>In Place</strong>

<em>Não em uma implementação típica</em>

<strong>Estável</strong>

<em>Sim</em>

---

### Quicksort

<strong>QuickSort é um algoritmo de classificação que escolhe um elemento <em>"pivô"</em> e reordena o array formando duas partições, de tal forma que todos os elementos menores que o pivô vem antes dele e os maiores elementos que o pivô vem depois. O algoritmo é aplicado recursivamente sob as partições até que o array esteja ordenado</strong>

<img src="https://i.stack.imgur.com/UWJZY.gif">

<stron>Lomuto partition, exemplo:</stron>

```java
public class Quicksort {

  public static int quickPartition(int[] arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
      if (arr[j] <= pivot) {
        i++;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
  }

  public static void quickSort(int[] arr, int low, int high) {
    if (low < high) {
      int pi = quickPartition(arr, low, high);
      quickSort(arr, low, pi - 1);
      quickSort(arr, pi + 1, high);
    }
  }
}
```

---

### Heap Sort

<strong>HeapSort é uma técnica de ordenação baseada em comparação na estrutura de dados binários (binary heap data structure). É semelhante ao Selection sort, em que primeiro o maior elemento e o colocamos no final da estrutura de dados. Em seguida é repetido o processo para os itens restantes.</strong>

<img src="https://i.stack.imgur.com/rxRGq.png">

<stron>Espaço auxiliar</stron>

<em>O(1)</em>

<stron>Tempo de complexidade</stron>

<em>O(n log n)</em>

<stron>Espaço auxiliar</stron>

<em>O(1)</em>

```java

```
