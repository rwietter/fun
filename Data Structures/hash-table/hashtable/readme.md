<div align="center"><h1>Hash Table</h1></div>

<br />
<br />

Hash functions são baseadas na tabela ASCII para calcular o índice, usando uma função de hash para calcular o índice podemos acessar em O(1) no melhor caso tanto para inserção, remoção e pesquisa. No pior caso será O(n) para todas essas TADs, por isso, funções de hashing são a parte mais importante dessa estrutura, exemplo:

```javascript
const fruits = {
	apples: 2.40,
	avocados: 7.90,
	banana: 3.54
}

const getForHash = fruits['avocados'];
console.log(getForHash);
```

Faz-se um cálculo para gerar um índice a partir da string e da tabela ASCII para cada letra, somando isso e retornando o índice para a string:

```java
class Main {
  public static void main(String[] args){

    Integer number = new Integer(2020); // 2020
    String str = new String("2020");
    System.out.println(number.hashCode()); // 2020
    System.out.println(str.hashCode()); // 1537276

    System.out.println("ABC".hashCode()); // 64578
    System.out.println("BAC".hashCode()); // 65508
    System.out.println("CAB".hashCode()); // 66468

    // A = 65
    // B = 66
    // C = 67
  }
}
```

O HashCode pode ser obtido por algumas fórmulas, no Java pode ser escrito como:

```java
s.charAt(0) * 31^n-1 + s.charAt(1) * 31^n-2 + ... + s.charAt(n-1)
```

Onde `s` é uma string e `n` é seu comprimento. Um exemplo:

```java
"ABC" = 'A' * 31^2 + 'B' * 31 + 'C' = 65 * 31^2 + 66 * 31 + 67 = 64578
```

<br />

---

<br />

#### Colisões

- Colisões acontecem quando o hash obtém o mesmo índice para chaves diferentes:

```java
"Aa" = 'A' * 31 + 'a' = 2112
"BB" = 'B' * 31 + 'B' = 2112
```

- No exemplo abaixo o resultado após o hash é `[as, looks, is, it, easy, Nothing]`, ou seja, houve uma colisão com o `as`, assim só trouxe uma delas. A ordem em que os elementos são retornados depende de seus códigos hash.

```java
public void hashset() {
  String[] words = new String("Nothing is as easy as it looks").split(" ");

  HashSet<String> hs = new HashSet<String>();

  for (String x : words) hs.add(x);

  System.out.println(hs.size() + " distinct words detected.");
  System.out.println(hs);
}
```

- Uma das formas de mitigar colisões é inserir os dados em uma linked list a partir de um slot da hash table, essa técnica é chamada de `Separate Chaining Collision Resolution`

<img width="50%" src="./assets/a97f64cc-297c-4998-8fe7-99f7c5a93417.png">

- Outra forma seria o `Linear Probing`, onde verifica-se caso o índice já está ocupado, por exemplo, caso não pudermos inserir em `k`, então tentaremos em `k+1 k+2 k+n`.

<br />

---

<br />

#### Load Factor

```
Number of items in hash table / Total number of slots
__________________
|  | 1 |  | * |  |
------------------

^ Load factor = 2/5 ^
> 1 and * is occupied <
```

- Caso exista mais itens na hash table que o número de slots, então possivelmente haverá colisões, o Load Factor deve ser 1.

```
________________
| 4 | 3 | 1 |  |
----------------
Load Factor = 3/4
```

- Devemos aplicar o `Resize` para diminuir as chances de colisões
- The rule of thumb is to make an array that is twice the size
- **Resize when your load factor is greater than 0.7**

```
_________________________
|  |  |  |  |  |  |  |  |
-------------------------
New Array = 0/8
```

- `Insert`

```
____________________________
|  | 4 |  | 1 | 3 |  |  |  |
----------------------------
Loader Factor = 3/8
```

---

- Boas hash functions devem distribuir os valores uniformemente

```
________________________________
| 2 |  | 6 | 4 |  | 10 | 12 |  |
--------------------------------
Loader Factor = 5/8
```

- Hash functions que formam grupos juntos produzem colisões

```
__________________________________
| 2 | 4 | 6 | 4 |  | 10 | 12 | 1 |
----------------------------------
Loader Factor = 7/8
```

<br />

---

<br />

### HashMap

- As HashMaps são uma forma de criar pares de chave : valor utilizando hash functions

```javascript
const fruits = {
	apples: 2.40,
	avocados: 7.90,
	banana: 3.54
}

const getForHash = fruits['avocados'];
console.log(getForHash);
```
