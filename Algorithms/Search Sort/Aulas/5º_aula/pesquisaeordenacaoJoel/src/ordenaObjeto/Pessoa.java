package ordenaObjeto;

public class Pessoa {
    private int id;
    private String sobrenome;
    private String nome;
    private int idade;
    
    public Pessoa(int id, String nome, String sobrenome, int idade) {
        this.id = id;
        this.nome = nome;
        this.sobrenome = sobrenome;
        this.idade = idade;
    }
    
    public void imprimePessoa(){
        System.out.print(id +" - ");
        System.out.print(sobrenome +", ");
        System.out.print(nome +" - ");
        System.out.print(idade);
    }
    
    public int getId(){
        return this.id;
    }
    
    public String getNome(){
        return this.nome;
    }
    
    public String getSobrenome(){
        return this.sobrenome;
    }
    
    public int getIdade(){
        return this.idade;
    }
}
