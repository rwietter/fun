package com.person;

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

  public void imprimePessoa() throws Exception {
    System.out.println(id + " - ");
    System.out.println(nome + " ");
    System.out.println(sobrenome + " - ");
    System.out.println(idade);
  }

  public int getId() {
    return this.id;
  }

  public void setId(int newId) {
    this.id = newId;
  }

  public String getNome() {
    return this.nome;
  }

  public void setName(String newName) {
    this.nome = newName;
  }

  public String getSobrenome() {
    return this.sobrenome;
  }

  public int getIdade() {
    return this.idade;
  }
}
