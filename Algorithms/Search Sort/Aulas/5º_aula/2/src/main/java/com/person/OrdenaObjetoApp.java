package com.person;

import java.util.Scanner;

import com.time.Time;

public class OrdenaObjetoApp {
	public static void main(String[] args) throws Exception {
		int arrSize = 10000;

		Contatos persons = new Contatos(arrSize);
		Time time = new Time();
		Gerador g = new Gerador();
		int id = 1;

		for (int i = 0; i < arrSize; i++) {
			persons.inserePessoa(id, g.geraNome(), g.geraSobrenome(), g.geraIdade());
			id++;
		}

		String formatString = "-----------------------------------";
		System.out.print(formatString + "\nQual algoritmo você deseja executar ?\n" + formatString
				+ "\n0) 'Bubblesort otimizado' por nome\n1) Bubblesort por Nome\n2) Bubblesort por Sobrenome\n"
				+ "3) Bubblesort por idade\n" + formatString
				+ "\n4) Selection por Nome\n5) Selection por Sobrenome\n6) Selection por idade\n" + formatString
				+ "\n7) Insertionsort por Nome\n8) Insertionsort por Sobrenome\n9) Insertionsort por idade\n" + formatString
				+ "\n10) Shellsort por idade\n11) Shellsort por nome\n12) Shellsort por sobrenome\n" + formatString
				+ "\n13) Quicksort por idade\n14) Quicksort por nome\n15) Quicksort por sobrenome\n" + formatString
				+ "\n\nInsira o número correspondente: ");

		Scanner scan = new Scanner(System.in);
		int key = scan.nextInt();
		scan.close();

		String result = "o resultado foi salvo em arquivo externo!";

		long initialTime = System.currentTimeMillis();
		switch (key) {
			case 0:
				persons.bubbleSortFirstNameAdapted();
				System.out.println("Bubblesort optimized per firstName, " + result);
				break;
			case 1:
				persons.bubbleSortFirstNameOriginal();
				System.out.println("BubbleSort per firstName, " + result);
				break;
			case 2:
				persons.bubbleSortLastName();
				System.out.println("BubbleSort per lastName, " + result);
				break;
			case 3:
				persons.bubbleSortAge();
				System.out.println("BubbleSort per age, " + result);
				break;
			case 4:
				persons.selectionSortFirstName();
				System.out.println("SelectionSort per firstName, " + result);
				break;
			case 5:
				persons.selectionSortLastName();
				System.out.println("SelectionSort per lastName, " + result);
				break;
			case 6:
				persons.selectionSortAge();
				System.out.println("SelectionSort per age, " + result);
				break;
			case 7:
				persons.insertionSortFirstName();
				System.out.println("InsertionSort per firstName, " + result);
				break;
			case 8:
				persons.insertionSortLastName();
				System.out.println("InsertionSort per lastName, " + result);
				break;
			case 9:
				persons.insertionSortIdade();
				System.out.println("InsertionSort per age, " + result);
				break;
			case 10:
				persons.shellSort();
				System.out.println("Shellsort per age, " + result);
				break;
			case 11:
				persons.shellsortName();
				System.out.println("Shellsort per firstName, " + result);
				break;
			case 12:
				persons.shellsortLastName();
				System.out.println("Shellsort per LastName, " + result);
				break;
			case 13:
				persons.quicksortAge(persons.getPerson(), 0, persons.getNumContatos() - 1);
				System.out.println("Quicksort per age, " + result);
				break;
			case 14:
				persons.quicksortFirstName(persons.getPerson(), 0, persons.getNumContatos() - 1);
				System.out.println("Quicksort per FirstName, " + result);
				break;
			case 15:
				persons.quicksortLastName(persons.getPerson(), 0, persons.getNumContatos() - 1);
				System.out.println("Quicksort per lastName, " + result);
				break;
			default:
				break;
		}
		long finalTime = System.currentTimeMillis();
		time.setTime(finalTime, initialTime);
		persons.imprimeContatos(time.getTime());
	}
}
