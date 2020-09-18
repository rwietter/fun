### Hash Table

#### Load Factor

```
Number of items in hash table / Total number of slots
__________________
|  | 1 |  | * |  |
------------------

^ Load factor = 2/5 ^
> 1 and * is occupied <
```

- Caso exista mais itens na hash table que o número de slots, então terá colisões, o Load Factor deve ser 1.

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
