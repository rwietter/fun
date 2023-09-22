package binary;

public class Person {
  private Client[] pers;
  private int len;

  public Person(int size) {
    this.pers = new Client[size];
    this.len = 0;
  }

  public Client[] getPerson() {
    return pers;
  }

  public void setLen(int len) {
    this.len = len;
  }

  public int getLen() {
    return this.len;
  }

  public void insertNewPerson(int code, int age, String name) {
    try {
      this.pers[len] = new Client(code, name, age);
      len++;
    } catch (Exception e) {
      System.out.println("Já está no limite");
    }
  }

  public void printPerson() {
    System.out.println("\n------------------------");
    for (int i = 0; i < this.len; i++) {
      this.pers[i].print();
    }
    System.out.println("------------------------\n");
  }

  /* --------------- Sequential Search --------------- */
  public Client sequentialSearchData(int key) {
    for (int i = 0; i < this.len; i++) {
      if (key == pers[i].getCode())
        return pers[i];
    }
    return null;
  }

  public Client binarySearch(int key) {
    int left = 0;
    int right = this.len;
    int middle;
    boolean found = false;

    try {
      while (!found) {
        middle = (int) ((left + right) / 2);
        if (pers[middle].getCode() == key) {
          found = true;
          return pers[middle];
        } else if (left > right) {
          throw new IllegalArgumentException("Client not found!");
        } else if (pers[middle].getCode() < key) {
          left = middle + 1;
        } else {
          right = middle - 1;
        }
      }
    } catch (Exception e) {
      throw new IllegalArgumentException(e.getCause());
    }
    return null;
  }

  /* --------------- Remove item --------------- */
  public Client removeItem(int data) {
    int left = 0;
    int right = this.len - 1;
    int middle;

    while (true) {
      middle = (int) ((left + right) / 2);
      if (pers[middle].getCode() == data) {
        pers[middle] = null;
        for (int i = 0; i < this.len; i++) {
          pers[middle] = pers[middle + 1];
        }
        this.len--;
        return pers[middle];
      } else if (left > right) {
        throw new IllegalArgumentException("Client not found!");
      } else {
        if (pers[middle].getCode() < data) {
          left = middle + 1;
        } else {
          right = middle - 1;
        }
      }
    }
  }

  /* --------------- Heapsort --------------- */
  public void heapsort() {
    int len = this.len;
    for (int i = len / 2 - 1; i >= 0; i--) {
      heapfy(pers, len, i);
    }
    for (int i = len - 1; i >= 0; i--) {
      Client temp = pers[0];
      pers[0] = pers[i];
      pers[i] = temp;
      heapfy(pers, i, 0);
    }
  }

  public void heapfy(Client[] pers, int len, int i) {
    int big = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < len && pers[left].getCode() > pers[big].getCode()) {
      big = left;
    }
    if (right < len && pers[right].getCode() > pers[big].getCode()) {
      big = right;
    }
    if (big != i) {
      Client temp = pers[i];
      pers[i] = pers[big];
      pers[big] = temp;
      heapfy(pers, len, big);
    }
  }
}
