package main.java.algorithm.contacts;

import main.java.algorithm.person.Person;

public class Contacts {
    private Person[] person;
    private int lenContacts;

    public Contacts(int sizeContacts) {
        this.person = new Person[sizeContacts];
        this.lenContacts = 0;
    }

    public void insertContact(int id, String name, String surname, int age) {
        this.person[lenContacts] = new Person(id, name, surname, age);
        this.lenContacts++;
    }

    public String getName() {
        return person[0].getName();
    }
}
