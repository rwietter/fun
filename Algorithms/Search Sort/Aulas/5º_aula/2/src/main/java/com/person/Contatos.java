package com.person;

import java.io.FileWriter;
import java.io.PrintWriter;

public class Contatos {
  private Pessoa[] vc; // vetor de contatos
  private int numContatos; // número de contatos

  public Contatos(int tamanho) {
    this.vc = new Pessoa[tamanho];
    this.numContatos = 0;
  }

  public Pessoa[] getPerson() {
    return vc;
  }

  public int getNumContatos() {
    return this.numContatos;
  }

  public void inserePessoa(int id, String nome, String sobrenome, int idade) {
    this.vc[numContatos] = new Pessoa(id, nome, sobrenome, idade);
    this.numContatos++;
  }

  public void imprimeContatos(double time) throws Exception {
    FileWriter archive = new FileWriter(
        "C:\\Users\\Mauricio\\Desktop\\bubble-insert-select-sort-assignment\\2\\orderListAlgorithm.txt");
    PrintWriter saveArchive = new PrintWriter(archive);
    for (int i = 0; i < this.numContatos; i++) {
      // vc[i].imprimePessoa();
      saveArchive.print(vc[i].getId() + " - ");
      saveArchive.print(vc[i].getNome() + " ");
      saveArchive.print(vc[i].getSobrenome() + " - ");
      saveArchive.print(vc[i].getIdade() + "\n");
    }
    saveArchive.printf("Tempo de Ordenação %.3f ms%n", time);
    saveArchive.printf("Tempo de ordenação %.2f min", (time / 60));
    saveArchive.flush();
    saveArchive.close();
  }

  // + ------------------------------------------------------------- +
  // + INSERTION SORT ALGORITHM +
  // + ------------------------------------------------------------- +
  public void insertionSortFirstName() {
    for (int i = 1; i < this.numContatos; ++i) {
      Pessoa key = vc[i];
      int j = i - 1;
      // while (j >= 0 && vc[j].getIdade() > key.getIdade()) // para ordenar por idade
      while (j >= 0 && vc[j].getNome().compareTo(key.getNome()) > 0) {
        vc[j + 1] = vc[j];
        j = j - 1;
      }
      vc[j + 1] = key;
    }

  }

  public void insertionSortLastName() {
    for (int i = 1; i < this.numContatos; i++) {
      Pessoa key = vc[i];
      int j = i - 1;
      while (j >= 0 && vc[j].getSobrenome().compareTo(key.getSobrenome()) > 0) {
        vc[j + 1] = vc[j];
        j--;
      }
      vc[j + 1] = key;
    }
  }

  public void insertionSortIdade() {
    for (int i = 1; i < this.numContatos; i++) {
      Pessoa key = vc[i];
      int j = i - 1;
      while (j >= 0 && vc[j].getIdade() > key.getIdade()) {
        vc[j + 1] = vc[j];
        j--;
      }
      vc[j + 1] = key;
    }
  }

  // + ------------------------------------------------------------- +
  // + BUBBLE SORT ALGORITHM +
  // + ------------------------------------------------------------- +

  public void bubbleSortId() {
    Pessoa aux;
    for (int i = this.numContatos - 1; i > 0; i--) {
      for (int j = 0; j < i; j++) {
        if (vc[j].getId() > vc[j + 1].getId()) {
          aux = vc[j];
          vc[j] = vc[j + 1];
          vc[j + 1] = aux;
        }
      }
    }
  }

  public void bubbleSortFirstNameAdapted() {
    int firstIndex, secondIndex;
    Pessoa aux;
    for (firstIndex = this.numContatos - 1; firstIndex > 0; firstIndex--) {
      for (secondIndex = 0; secondIndex < firstIndex; secondIndex++) {
        if (vc[firstIndex].getNome().compareTo(vc[secondIndex].getNome()) < 0) {
          aux = vc[firstIndex];
          vc[firstIndex] = vc[secondIndex];
          vc[secondIndex] = aux;
        }
      }
    }
  }

  public void bubbleSortFirstNameOriginal() {
    Pessoa key;
    for (int i = this.numContatos - 1; i > 0; i--) {
      for (int j = 0; j < i; j++) {
        if (vc[j].getNome().compareTo(vc[j + 1].getNome()) > 0) {
          key = vc[j];
          vc[j] = vc[j + 1];
          vc[j + 1] = key;
        }
      }
    }
  }

  public void bubbleSortLastName() {
    Pessoa key;
    for (int i = this.numContatos - 1; i > 0; i--) {
      for (int j = 0; j < i; j++) {
        if (vc[j].getSobrenome().compareTo(vc[j + 1].getSobrenome()) > 0) {
          key = vc[j];
          vc[j] = vc[j + 1];
          vc[j + 1] = key;
        }
      }
    }
  }

  public void bubbleSortAge() {
    Pessoa aux;
    for (int i = this.numContatos - 1; i > 0; i--) {
      for (int j = 0; j < i; j++) {
        if (vc[j].getIdade() > vc[j + 1].getIdade()) {
          aux = vc[j];
          vc[j] = vc[j + 1];
          vc[j + 1] = aux;
        }
      }
    }
  }

  // + ------------------------------------------------------------- +
  // + SELECTION SORT ALGORITHM +
  // + ------------------------------------------------------------- +
  public void selectionSortAge() {
    int menorIndex = 0;
    Pessoa aux;
    for (int i = 0; i < this.numContatos - 1; i++) {
      menorIndex = i;
      for (int j = i; j < this.numContatos; j++) {
        if (vc[j].getIdade() < vc[menorIndex].getIdade()) {
          menorIndex = j;
        }
      }
      aux = vc[menorIndex];
      vc[menorIndex] = vc[i];
      vc[i] = aux;
    }
  }

  public void selectionSortFirstName() {
    int menorIndex = 0;
    Pessoa aux;
    for (int i = 0; i < this.numContatos - 1; i++) {
      menorIndex = i;
      for (int j = i; j < this.numContatos; j++) {
        if (vc[j].getNome().compareTo(vc[menorIndex].getNome()) < 0) {
          menorIndex = j;
        }
      }
      aux = vc[menorIndex];
      vc[menorIndex] = vc[i];
      vc[i] = aux;
    }
  }

  public void selectionSortLastName() {
    int menorIndex = 0;
    Pessoa aux;
    for (int i = 0; i < this.numContatos - 1; i++) {
      menorIndex = i;
      for (int j = i; j < this.numContatos; j++) {
        if (vc[j].getSobrenome().compareTo(vc[menorIndex].getSobrenome()) < 0) {
          menorIndex = j;
        }
      }
      aux = vc[menorIndex];
      vc[menorIndex] = vc[i];
      vc[i] = aux;
    }
  }

  public void selectionSortId() {
    int menorIndex;
    Pessoa aux;
    for (int i = 0; i < this.numContatos - 1; i++) {
      menorIndex = i;
      for (int j = i; j < this.numContatos; j++) {
        if (vc[j].getId() < vc[menorIndex].getId()) {
          menorIndex = j;
        }
      }
      aux = vc[menorIndex];
      vc[menorIndex] = vc[i];
      vc[i] = aux;
    }
  }

  // + ------------------------------------------------------------- +
  // + SHELL SORT ALGORITHM +
  // + ------------------------------------------------------------- +
  public void shellSort() {
    int divider = 1, j = 0;
    while (divider < this.numContatos) {
      divider *= 3 + 1;
    }
    divider /= 3;
    Pessoa aux;
    while (divider > 0) {
      for (int i = divider; i < this.numContatos; i++) {
        aux = vc[i];
        j = i;
        while (j >= divider && vc[j - divider].getIdade() > aux.getIdade()) {
          vc[j] = vc[j - divider];
          j -= divider;
        }
        vc[j] = aux;
      }
      divider /= 2;
    }
  }

  public void shellsortName() {
    int divider = 1, j = 0;
    while (divider < this.numContatos) {
      divider *= 3 + 1;
    }
    divider /= 3;
    Pessoa aux;
    while (divider > 0) {
      for (int i = divider; i < this.numContatos; i++) {
        aux = vc[i];
        j = i;
        while (j >= divider && vc[j - divider].getNome().compareTo(aux.getNome()) > 0) {
          vc[j] = vc[j - divider];
          j -= divider;
        }
        vc[j] = aux;
      }
      divider /= 2;
    }
  }

  public void shellsortLastName() {
    int divider = 1, j = 0;
    Pessoa aux;
    while (divider < this.numContatos) {
      divider *= 3 + 1;
    }
    divider /= 3;
    while (divider > 0) {
      for (int i = divider; i < this.numContatos; i++) {
        aux = vc[i];
        j = i;
        while (j >= divider && vc[j - divider].getSobrenome().compareTo(aux.getSobrenome()) > 0) {
          vc[j] = vc[j - divider];
          j -= divider;
        }
        vc[j] = aux;
      }
      divider /= 2;
    }
  }

  // + ------------------------------------------------------------- +
  // + QUICK SORT ALGORITHM +
  // + ------------------------------------------------------------- +
  public int quicksortAgePartition(Pessoa[] person, int low, int high) {
    Pessoa pivot = person[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
      if (person[j].getIdade() <= pivot.getIdade()) {
        i++;
        Pessoa temp = person[i];
        person[i] = person[j];
        person[j] = temp;
      }
    }
    Pessoa temp = person[i + 1];
    person[i + 1] = person[high];
    person[high] = temp;
    return (i + 1);
  }

  public void quicksortAge(Pessoa[] person, int low, int high) {
    if (low < high) {
      int pi = quicksortAgePartition(person, low, high);
      quicksortAge(person, low, pi - 1);
      quicksortAge(person, pi + 1, high);
    }
  }

  public int quicksortFirstNamePartition(Pessoa[] person, int low, int high) {
    Pessoa pivot = person[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
      if (person[j].getNome().compareTo(pivot.getNome()) < 0) {
        i++;
        Pessoa temp = person[i];
        person[i] = person[j];
        person[j] = temp;
      }
    }
    Pessoa temp = person[i + 1];
    person[i + 1] = person[high];
    person[high] = temp;
    return (i + 1);
  }

  public void quicksortFirstName(Pessoa[] person, int low, int high) {
    if (low < high) {
      int pi = quicksortFirstNamePartition(person, low, high);
      quicksortFirstName(person, low, pi - 1);
      quicksortFirstName(person, pi + 1, high);
    }
  }

  public int quicksortLastNamePartition(Pessoa[] person, int low, int high) {
    Pessoa pivot = person[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
      if (person[j].getSobrenome().compareTo(pivot.getSobrenome()) < 0) {
        i++;
        Pessoa temp = person[i];
        person[i] = person[j];
        person[j] = temp;
      }
    }
    Pessoa temp = person[i + 1];
    person[i + 1] = person[high];
    person[high] = temp;
    return i + 1;
  }

  public void quicksortLastName(Pessoa[] person, int low, int high) {
    if (low < high) {
      int pi = quicksortLastNamePartition(person, low, high);
      quicksortLastName(person, low, pi - 1);
      quicksortLastName(person, pi + 1, high);
    }
  }

  // + ------------------------------------------------------------- +
  // + QUICK SORT ALGORITHM +
  // + ------------------------------------------------------------- +
  public void heapsortAge() {

  }
}

/*
 * O algoritmo passa várias vezes pela lista dividindo o grupo maior em menores
 * Nos grupos menores é aplicado o método da ordenação por inserção.
 */
