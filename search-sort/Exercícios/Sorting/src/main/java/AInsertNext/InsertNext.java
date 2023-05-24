package AInsertNext;

import java.beans.Encoder;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Base64;
import java.util.List;
import java.util.Scanner;
import java.util.Stack;

public class InsertNext {
  private String name;

  public InsertNext(String keyword) {
    this.name = keyword;
  }

  public String getElement() {
    return this.name;
  }

  public void setElement(String newName) {
    this.name = newName;
  }

  public int getElementCompareTo(InsertNext el) {
    int response = 0;
    if (this.name.compareTo(el.getElement()) > 0) {
      response = -1;
    }
    if (this.name.compareTo(el.getElement()) > 0) {
      response = 1;
    }
    return response;
  }

  public static List<InsertNext> insertionSortArrayList(List<InsertNext> arr) {
    int j = 0;
    while (j < arr.size()) {
      InsertNext current = arr.get(j);
      int i = j - 1;
      while ((i >= 0) && ((arr.get(i).getElementCompareTo(current)) == 1)) {
        arr.set(i + 1, arr.get(i));
        i--;
      }
      arr.set(i + 1, current);
      j++;
    }
    return arr;
  }

  public static void main(String[] args) {
    int j = 0;
    String keyword;
    Stack<InsertNext> list = new Stack<>();

    Scanner scan = new Scanner(System.in);
    // java.util.Base64.Encoder encoder = Base64.getEncoder();
    // java.util.Base64.Decoder decoder = Base64.getMimeDecoder();

    System.out.print("Quantos valores deseja ler: ");
    int values = scan.nextInt();
    while (j < values) {
      System.out.print("Digite a palavra a ser ordenada: ");
      keyword = scan.next();
      // keyword = encoder.encodeToString(keyword.getBytes());
      list.add(new InsertNext(keyword));
      j++;
    }
    scan.close();

    long startTime1 = System.nanoTime();
    insertionSortArrayList(list);
    long endTime1 = System.nanoTime();

    list.forEach(e -> System.out.print(e.getElement() + ", "));
    float solveNanoTime = (startTime1 - endTime1);
    String str3 = String.format("%.2f", solveNanoTime);
    System.out.println("\nInsertion Sort runtime: " + str3);
  }
}

/*
 * 1 – Faça um programa que leia n nomes inserindo-os em uma lista de forma
 * ordenada utilizando a ideia do algoritmo da inserção. No final, o programa
 * deve mostrar todos os nomes ordenados alfabeticamente.
 */
