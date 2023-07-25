package binary;

public class Client {
  private int code;
  private String name;
  private int age;

  /* Constructor */
  public Client(int code, String name, int age) {
    this.code = code;
    this.name = name;
    this.age = age;
  }

  /* Getters and Setters */
  public int getCode() {
    return code;
  }

  public void setCode(int code) {
    this.code = code;
  }

  public String getName() {
    return name;
  }

  public void setName(String name) {
    this.name = name;
  }

  public int getAge() {
    return age;
  }

  public void setAge(int age) {
    this.age = age;
  }

  /* print clients */
  public void print() {
    System.out.print(code + " - ");
    System.out.print(name + " ");
    System.out.println(age);
  }
}
