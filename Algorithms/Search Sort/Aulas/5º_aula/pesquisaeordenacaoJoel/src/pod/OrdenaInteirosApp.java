package pod;

import java.util.Random;

public class OrdenaInteirosApp {

    public static void main(String[] args) {
        int tamanho = 10;

        int[] v = new int[tamanho];

        insereValores(v);

        int n = v.length;

        // InsertionSort(v,n);
        SelectionSort(v, n);
        // BubbleSort(v,n);
        // ShellSort(v,n);

        // imprime valores ordenados;
        System.out.println("===== Vetor Ordenado =====");
        imprimeValores(v);
    }

    static void insereValores(int[] v) {
        Random gerador = new Random();
        int n = v.length;
        for (int i = 0; i < n; i++) {
            v[i] = gerador.nextInt(100);
        }
    }

    static void imprimeValores(int[] v) {
        int n = v.length;
        for (int i = 0; i < n; i++) {
            System.out.printf("[%d] = %2d\n", i, v[i]);
        }
    }

    static void InsertionSort(int[] v, int n) {
        for (int i = 1; i < n; ++i){
            int key = v[i];
            int j = i - 1;

            while (j >= 0 && v[j] > key) {
                v[j + 1] = v[j];
                j = j - 1;
            }
            v[j + 1] = key;
        }

    }


    static void SelectionSort(int[] v, int n) {
        int i, j, menor_idx, aux;
        for (i = 0; i < n - 1; i++) {
            menor_idx = i;
            for (j = i + 1; j < n; j++)
                if (v[j] < v[menor_idx]) {
                    menor_idx = j;
                }
//            System.out.printf("==== Passo(%d) i=%d ==== \n", i, i);
//            imprimeValores(v);
            aux = v[menor_idx];
            v[menor_idx] = v[i];
            v[i] = aux;
        }
    }

    static void BubbleSort(int[] v, int n) {
        int i, j, aux;
        for (i = n - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                System.out.printf("==== Passo(%d) i=%d, j=%d ==== \n", i, i, j);
                imprimeValores(v);
                if (v[j] > v[j + 1]) {
                    aux = v[j];
                    v[j] = v[j + 1];
                    v[j + 1] = aux;
                }
            }
        }
    }

    static void ShellSort(int[] v, int n) {
        int h = 1;
        while (h < n) {
            h = h * 3 + 1;
        }

        h = h / 3;
        int c, j;

        while (h > 0) {
            for (int i = h; i < n; i++) {
                c = v[i];
                j = i;
                while (j >= h && v[j - h] > c) {
                    v[j] = v[j - h];
                    j = j - h;
                }
                v[j] = c;
            }
            h = h / 2;
        }
    }
}
