package ordenaObjeto;

public class Contatos {
    private Pessoa[] vc; //vetor de contatos
    private int numContatos; //número de contatos

    public Contatos(int tamanho) {
        vc = new Pessoa[tamanho];
        this.numContatos = 0;
    }
    
    public void inserePessoa(int id, String nome, String sobrenome, int idade){
        vc[numContatos] = new Pessoa(id, nome, sobrenome, idade);
        numContatos ++;
    }
    
    public void imprimeContatos(){
        for(int i =0; i <numContatos;i++) {
            vc[i].imprimePessoa();
            System.out.println(" ");
        }
    }
    
    public void insertionSort(){
        for (int i=1; i<this.numContatos; ++i)
            
        {
            Pessoa key = vc[i];
            int j = i-1;    
            
            while (j>=0 && vc[j].getIdade() > key.getIdade())  // para ordenar por idade
          //  while (j>=0 && vc[j].getSobrenome().compareTo(key.getSobrenome()) >0) // para ordenar por sobrenome
            {             
                vc[j + 1] = vc[j];                
                j = j-1;
            }    
            vc[j+1] = key;   
        }
    }
}
