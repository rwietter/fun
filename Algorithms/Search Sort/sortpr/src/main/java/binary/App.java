package binary;

import java.util.Scanner;

public class App {
  public static void main(String args[]) {
    Ascii ascii = new Ascii();
    System.out.println(ascii.getAscii());

    int maxClient = 10;
    int code = 1;

    Person client = new Person(maxClient);
    Gen gen = new Gen();
    Scanner scan = new Scanner(System.in);

    String hr = "--------------------------- ";
    System.out.println("\n" + hr + "Sequential and Binary Search" + hr + "\n");

    System.out.print("Reserved Storage: ");
    int reserved = scan.nextInt();
    if (reserved < maxClient / 2) {
      for (int j = 0; j < maxClient - reserved; j++) {
        client.insertNewPerson(code, gen.getRandomAge(), gen.getRandomName());
        code++;
      }
    } else {
      throw new IllegalAccessError("Value is over the limit, please enter a smaller value.");
    }
    code += -1;

    /* Menu */
    String menu = "1 - Cadastrar\n2 - Pesquisar - Com Busca Sequencial\n"
        + "3 - Pesquisar - Com Busca Binária\n4 - Excluir\n5 - Listar\n0 - Sair\nOpção: ";
    System.out.print(menu);
    int option = scan.nextInt();

    int age, data;
    String name = "", search = "Enter id for search: ";

    while (option != 0) {
      if (option == 1) {
        code++;
        System.out.print("Age: ");
        age = scan.nextInt();

        System.out.print("Name: ");
        name = scan.next();

        client.insertNewPerson(code, age, name);

      } else if (option == 2) {
        Client person = null;
        System.err.print(search);
        data = scan.nextInt();
        if (data > 0 && data < client.getLen() + 1) {
          person = client.sequentialSearchData(data);
        }

        if (person != null) {
          System.out.print("\n" + hr + "\n\nFound data:\n");
          person.print();
          System.out.print("\n" + hr);
        } else {
          System.out.print("\n" + hr + "\n\nClient not exists in database!\n");
          System.out.print("\n" + hr);
        }

      } else if (option == 3) {
        Client person = null;
        System.err.print(search);
        data = scan.nextInt();
        client.heapsort();
        if (data > 0 && data < client.getLen() + 1) {
          person = client.binarySearch(data);
        } else {
          person = null;
        }

        if (person != null) {
          System.out.print("\n" + hr + "\n\nFound data:\n");
          person.print();
          System.out.print("\n" + hr);
        } else {
          System.out.print("\n" + hr + "\n\nClient not exists in database!\n");
          System.out.print("\n" + hr);
        }

      } else if (option == 4) {
        System.out.print("Insert id to exclude: ");
        data = scan.nextInt();
        client.removeItem(data);
      } else if (option == 5) {
        client.printPerson();
      }
      System.out.print("\n\n" + menu);
      option = scan.nextInt();
    }
    scan.close();
  }
}
