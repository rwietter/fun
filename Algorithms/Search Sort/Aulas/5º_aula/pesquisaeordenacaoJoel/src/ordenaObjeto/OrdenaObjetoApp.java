package ordenaObjeto;

public class OrdenaObjetoApp {
    public static void main(String[] args) {      
     int tamanho = 10;
     Contatos persons;
     persons = new Contatos(tamanho);     
     Gerador g = new Gerador();
     int id = 1;
     for(int i = 0;i < tamanho; i++) {
       persons.inserePessoa(id, g.geraNome(), g.geraSobrenome(), g.geraIdade());
       id++;
     }
        persons.insertionSort(); 
        persons.imprimeContatos();
    }
}
