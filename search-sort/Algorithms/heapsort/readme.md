# HeapSort

<strong>A ordenação de heap funciona visualizando os elementos do array como um tipo de árvore binária completa de heap.</strong>

---

<strong>Árvore binária completa:</strong>

<em>todos os níveis, exceto possivelmente o último, são preenchidos</em>

<em>todos os nós estão o mais à esquerda possível</em>

<em><strong>Max heap:</strong> maior elemento está na raiz</em>

<em><strong>Min heap:</strong> menor elemento está na raiz</em>

---

<strong>Heapify</strong>

<em>Heapify é o processo de criar uma estrutura de dados de heap a partir de uma árvore binária. É usado para criar um Min-Heap ou um Max-Heap.</em>

<strong>Usabilidade de uma estrutura de Heap:</strong>

<ul>
  <li>O heap é usado ao implementar uma fila de prioridade.</li>

  <li>Algoritmo de Dijkstra</li>

  <li>Heap Sort</li>
</ul>

---

## Heapsort

<strong>Se o índice i for qualquer elemento, o índice 2i+1 será o filho à esquerda e, o índice 2i+2 será seu filho à direta. Além disso, o pai de qualquer índice será (i-1)/2</strong>

<strong>É uma estrutura de heap se:</strong>

<em>É uma árvore binária completa</em>

<em>Todos os nós da árvore seguem a propriedade de que são maiores que seus filhos, ou seja, o maior elemento está na raiz e seus filhos e menores que a raiz e assim por diante. Tal pilha é chamada de max-heap. Se, em vez disso, todos os nós forem menores que seus filhos, isso será chamado de min-heap</em>

<strong>Para manter a propriedade max-heap em uma árvore em que ambas as subárvores são max-heaps, precisa-se executar heapify no elemento raiz repetidamente até que ele seja maior que seus filhos ou se torne um nó folha.</strong>

```java
public class HeapSort {
  public static void main(String[] args) {
    int arr[] = { 3, 64, 2, 12, 5 };
    int len = arr.length;
    heapsort(arr, len);
    for (int i : arr) {
      System.out.println(" " + i);
    }
  }

  static void heapsort(int arr[], int len) {
    // build max-heap
    for (int i = len / 2 - 1; i >= 0; i--) {
      heapfy(arr, len, i);
    }
    // heapsort
    for (int i = len - 1; i >= 0; i--) {
      int temp = arr[0];
      arr[0] = arr[i];
      arr[i] = temp;
      heapfy(arr, i, 0); // heapfy root element
    }
  }

  static void heapfy(int arr[], int len, int i) {
    int maior = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < len && arr[left] > arr[maior]) {
      maior = left;
    }
    if (right < maior && arr[right] > arr[maior]) {
      maior = right;
    }
    if (maior != i) {
      int temp = arr[i];
      arr[i] = arr[maior];
      arr[maior] = temp;
      heapfy(arr, len, maior);
    }
  }
}
```
