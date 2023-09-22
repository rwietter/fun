package src.countingsort;

public class CountingSort {

  public void countingSort(int data[], int len, int place, int max) {

    int[] output = new int[len + 1]; // tamanho do array mais 1

    int[] count = new int[max + 1]; // aloca memória para o tamanho do maior elemento

    for (int i = 0; i < max; ++i)
      count[i] = 0; // preenche o array do tamanho do maior elemento com zeros

    for (int i = 0; i < len; i++)
      count[(data[i] / place) % 10]++; // soma 1 ao indíce que é gerado pela divisão e resto da divisão do elemento

    for (int i = 1; i < 10; i++)
      count[i] += count[i - 1]; // faz a contagem de indices para servir a ordenação de output

    for (int i = len - 1; i >= 0; i--) {
      output[count[(data[i] / place) % 10] - 1] = data[i]; // troca os valores de acordo com o índice do array count
      count[(data[i] / place) % 10]--; // decrementa a posição do array count que vai de 0 a 9 até n elementos
    }

    /**
     * update data sort
     * 
     */
    for (int i = 0; i < len; i++) {
      data[i] = output[i];
    }
  }
}
