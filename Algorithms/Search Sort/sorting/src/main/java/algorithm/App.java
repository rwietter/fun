import main.java.algorithm.contacts.Contacts;
import main.java.algorithm.generator.Generator;

public class App {
    public static void main(String args[]) {
        int size = 1000;

        Generator generator = new Generator();
        Contacts contact = new Contacts(size);

        int id = 1;
        for (int i = 0; i < size; i++) {
            contact.insertContact(id, generator.getName(), generator.getSurname(), generator.getAge());
            id++;
        }

        System.out.print(
                "1- insertionSort\n2- selectionSort\n3- bubbleSort\n4- shellSort\n5- quickSort\n6- heapSort\nEscolha uma opção: ");
        Scanner scan = new Scanner(System.in);
        int key = scan.next();

        System.out.println(contact.getName());

        // if (key == 1)
        // insertionSort();
        // if (key == 2)
        // selectionSort();
        // if (key == 3)
        // bubbleSort();
        // if (key == 4)
        // shellSort();
        // if (key == 5)
        // quickSort();
        // if (key == 6)
        // heapSort();

    }
}
