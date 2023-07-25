package binarySearch;

public class Client {
  private Person[] pers;
  private int maxClient;

  public Client(int size) {
    this.pers = new Person[size];
    this.maxClient = 0;
  }

  public Person[] getPerson() {
    return pers;
  }

  public int getMaxClient() {
    return this.maxClient;
  }

  public void insertNewPerson(int code, int age, String name) {
    this.pers[maxClient] = new Person(code, name, age);
    maxClient++;
  }

  public void printPerson() {
    System.out.println("\n------------------------");
    for (int i = 0; i < this.maxClient; i++) {
      this.pers[i].print();
    }
    System.out.println("------------------------\n");
  }

  public boolean getPersonCode(int code) {
    for (int i = 0; i < this.maxClient; i++) {
      if (code == pers[i].getCode()) {
        return false;
      }
    }
    return true;
  }

  /* --------------- Sequential Search --------------- */
  public Person sequentialSearchData(int data, int type, String dataName) {
    if (type == 1) {
      for (int i = 0; i < this.maxClient; i++) {
        if (data == pers[i].getAge())
          return pers[i];
      }
    } else if (type == 2) {
      for (int i = 0; i < this.maxClient; i++) {
        if (data == pers[i].getCode())
          return pers[i];
      }
    } else {
      for (int i = 0; i < this.maxClient; i++) {
        if (pers[i].getName().compareTo(dataName) > 0) {
          return pers[i];
        }
      }
    }
    throw new IllegalArgumentException("Dado não encontrado");
  }

  /* --------------- Binary Search --------------- */
  public Person binarySearch(int data, int key, String dataString) {
    heapsort();
    int left = 0;
    int right = this.maxClient;
    int middle;

    if (key == 1) {
      while (left < right) {
        middle = (int) ((left + right) / 2);
        if (pers[middle].getAge() == data) {
          return pers[middle];
        } else {
          if (data < pers[middle].getAge()) {
            right = middle - 1;
          } else {
            left = middle + 1;
          }
        }
      }
    } else if (key == 2) {
      while (left < right) {
        middle = (int) ((left + right) / 2);
        if (pers[middle].getCode() == data) {
          return pers[middle];
        } else {
          if (data < pers[middle].getCode()) {
            right = middle - 1;
          } else {
            left = middle + 1;
          }
        }
      }
    } else {
      while (left < right) {
        middle = (int) ((left + right) / 2);
        if (pers[middle].getName().compareTo(dataString) > 0) {
          return pers[middle];
        } else {
          if (data < pers[middle].getCode()) {
            right = middle - 1;
          } else {
            left = middle + 1;
          }
        }
      }
    }
    return pers[0];
  }

  /* --------------- Remove item --------------- */
  public void removeItem(int data) {
    System.out.println("Hi");
  }

  /* --------------- Heapsort --------------- */
  public void heapsort() {
    int len = this.maxClient;
    for (int i = len / 2 - 1; i >= 0; i--) {
      heapfy(pers, len, i);
    }
    for (int i = len - 1; i >= 0; i--) {
      Person temp = pers[0];
      pers[0] = pers[i];
      pers[i] = temp;
      heapfy(pers, i, 0);
    }
  }

  public void heapfy(Person[] pers, int len, int i) {
    int big = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < len && pers[left].getAge() > pers[big].getAge()) {
      big = left;
    }
    if (right < len && pers[right].getAge() > pers[big].getAge()) {
      big = right;
    }
    if (big != i) {
      Person temp = pers[i];
      pers[i] = pers[big];
      pers[big] = temp;
      heapfy(pers, len, big);
    }
  }
}
