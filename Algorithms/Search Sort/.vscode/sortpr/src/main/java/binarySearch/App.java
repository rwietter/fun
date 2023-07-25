package binarySearch;

import java.util.Scanner;

public class App {
  public static void main(String args[]) {
    int maxClient = 20;
    int code = 1;

    Client client = new Client(maxClient);
    Generator gen = new Generator();
    Scanner scan = new Scanner(System.in);
    App app = new App();

    for (int j = 0; j < maxClient - 1; j++) {
      client.insertNewPerson(code, gen.getRandomAge(), gen.getRandomName());
      code++;
    }

    /* Menu */
    String hr = "--------------------------- ";

    System.out.println("\n" + hr + "Pesquisa Binária e Sequencial" + hr + "\n");
    String menu = "1 - Cadastrar\n2 - Pesquisar - Com Busca Sequencial\n"
        + "3 - Pesquisar - Com Busca Binária\n4 - Excluir\n5 - Listar\n0 - Sair\nOpção: ";
    System.out.print(menu);
    int option = scan.nextInt();

    int cod, age, type, data, search;
    String name = "";
    String switchMenu = "\n" + hr + "\nBinary Search\n1| Age\n2| Code\n3| Name\nInsert: ";

    while (option != 0) {
      if (option == 1) {

        System.out.print("\n" + hr + "\nCode: ");
        cod = scan.nextInt();
        app.thisCodeExists(client, cod);
        System.out.print("Age: ");
        age = scan.nextInt();
        System.out.print("Name: ");
        name = scan.next();

        client.insertNewPerson(cod, age, name);
        client.printPerson();

      } else if (option == 2) {
        System.out.print(switchMenu);
        type = scan.nextInt();
        String dataName = "";
        data = 0;
        if (type < 3 && type > 0) {
          System.err.print("Insert data to search: ");
          data = scan.nextInt();
        } else {
          System.out.print("Insert name: ");
          dataName = scan.next();
        }
        client.sequentialSearchData(data, type, dataName).print();

      } else if (option == 3) {
        System.out.print(switchMenu);
        type = scan.nextInt();
        String dataName = "";
        data = 0;
        if (type < 3 && type > 0) {
          System.out.print("Insert data to search: ");
          data = scan.nextInt();
        } else {
          System.out.print("Insert name: ");
          dataName = scan.next();
        }
        client.binarySearch(data, type, dataName).print();

      } else if (option == 5) {
        client.printPerson();
      }
      System.out.print("\n\n" + menu);
      option = scan.nextInt();
    }
    scan.close();

  }

  public void thisCodeExists(Client client, int cod) {
    if (client.getPersonCode(cod) == false) {
      throw new IllegalArgumentException("This code already exists");
    }
  }
}
