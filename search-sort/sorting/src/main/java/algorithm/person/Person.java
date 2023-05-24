package main.java.algorithm.person;

public class Person {
    private int age;
    private String name;
    private String surname;
    private int id;

    public Person(int age, String name, String surname, int id) {
        this.setAge(age);
        this.setName(name);
        this.setSurname(surname);
        this.setId(id);
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getSurname() {
        return surname;
    }

    public void setSurname(String surname) {
        this.surname = surname;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }
}
