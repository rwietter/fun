**Busca por padrões**: cláusula `[NOT] LIKE`

**Teste de existência de valores nulos**: cláusula `IS [NOT] NULL`

**Busca por intervalos de valores**: cláusula `[NOT] BETWEEN valor1 AND valor2`

**Teste de pertinência elemento-conjunto**: cláusula `[NOT] IN`

**Like e not like**: cláusula `[NOT] LIKE` '%valor%' | '%valor' | 'valor%' | 'valor' | 'a-f'

---

**WHERE**: pode ser qualquer expressão SQL, especificada usando operadores de comparação ou lógicos como `>, <, =, <>, >=, <=, LIKE, NOT, IN, BETWEEN` etc.

```sql
SELECT * FROM Cars WHERE status = 'READY'

-- AND
SELECT P.name FROM persons AS P WHERE P.gender = 'M' AND P.age > 20;

-- OR
SELECT P.name FROM persons AS P WHERE P.gender = 'M' OR P.age < 20;

-- Both
SELECT name FROM persons WHERE (gender = 'M' AND age < 20) OR (gender = 'F' AND age > 20);

-- IN
SELECT * FROM Cars WHERE ( Cars.status = 'Waiting' OR Cars.status = 'Working' )
SELECT * FROM Cars WHERE Cars.status IN ( 'Waiting', 'Working' )
```

---

**CASE**: permite que você especifique uma série de condições e valores de retorno, semelhante a uma instrução `IF-THEN-ELSE` ou `SWITCH-CASE` em outras linguagens de programação.

```sql

SELECT
  P.name,
  CASE
    WHEN P.age < 18 THEN 'minor'
    WHEN P.age >= 18 AND P.age < 65 THEN 'adult'
    ELSE 'senior'
  END AS age_group
FROM
  people AS P

-- Example 2
SELECT 
    CASE
        WHEN Col1 < 50 THEN 'under'
        WHEN Col1 > 50 AND Col1 < 100 THEN 'between'
        ELSE 'over'
    END threshold
FROM
    TableName
```

- Somar valores com condicional CASE

```sql
SELECT
  COUNT(Id) AS ItemsCount,
  SUM(
    CASE
      WHEN PriceRating = 'Expensive' THEN 1
      ELSE 0
    END
  ) AS ExpensiveItemsCount
FROM
  ItemSales

-- OR
SELECT
  COUNT(Id) AS ItemsCount,
  SUM(
    CASE
      PriceRating
      WHEN 'Expensive' THEN 1
      ELSE 0
    END
  ) AS ExpensiveItemsCount
FROM
  ItemSales
```

- CASE com boolean expression

```sql
SELECT
  Id,
  ItemId,
  Price,
  CASE
    WHEN Price < 10 THEN 'CHEAP'
    WHEN Price < 20 THEN 'AFFORDABLE'
    ELSE 'EXPENSIVE'
  END AS PriceRating
FROM
  ItemSales
```

- CASE com IS NULL

```sql
SELECT
  ID,
  REGION,
  CITY,
  DEPARTMENT,
  EMPLOYEES_NUMBER
FROM
  DEPT
ORDER BY
  CASE
    WHEN REGION IS NULL THEN 1
    ELSE 0
  END,
  REGION
```

---

**Intervalos com BETWEEN**

```sql
SELECT
  *
FROM
  Consultas
WHERE
  hora BETWEEN '14:00' AND '18:00'
```

---

**Contains com IN**

```sql
SELECT
  *
FROM
  Médicos
WHERE
  cidade = 'Florianópolis'
  AND especialidade IN ('cardiologia', 'traumatologia', 'cardiologia')
```

---

**GROUP BY**: agrupa as linhas que têm os mesmos valores em linhas de resumo. GROUP BY é frequentemente usada com funções agregadas ( COUNT(), MAX(), MIN(), SUM(), AVG() ) para agrupar o conjunto de resultados por uma ou mais colunas.

```sql
-- encontre o número de clientes em cada país
SELECT
  COUNT(CustomerID),
  Country
FROM
  Customers
GROUP BY
  Country
ORDER BY
  COUNT(CustomerID) DESC;

-- Dê-me a soma de MonthlySalary para cada EmpID
SELECT EmpID, SUM (MonthlySalary) FROM Employee GROUP BY EmpID
```

- GROUP BY pode ser usado com qualquer função agregada, como COUNT(), MAX(), MIN(), SUM(), AVG().

```sql
SELECT
  a.Id,
  a.Name,
  COUNT(*) BooksWritten
FROM
  BooksAuthors ba
  INNER JOIN Authors a ON a.id = ba.authorid
GROUP BY
  a.Id,
  a.Name
HAVING
  COUNT(*) > 1 -- equals to HAVING BooksWritten > 1 ;
```

---

**HAVING**: A cláusula HAVING foi adicionada ao SQL porque a palavra-chave WHERE não pode ser usada com funções agregadas.

```sql
SELECT column_name(s)
FROM table_name
WHERE condition
GROUP BY column_name(s)
HAVING condition
ORDER BY column_name(s);

-- listar o número de clientes em cada país. Incluir apenas países com mais de 5 clientes.
SELECT
  COUNT(CustomerID),
  Country
FROM
  Customers
GROUP BY
  Country
HAVING
  COUNT(CustomerID) > 5
ORDER BY
  COUNT(CustomerID) DESC;

-- Agruoar e encontrar duplicatas de OrderID
SELECT OrderID, COUNT(OrderID)
FROM Orders
GROUP BY OrderID
HAVING COUNT(OrderID) > 1
```

---

**ORDER BY**: ordenação de resultados.

```sql
SELECT * FROM Employees ORDER BY LName DESC
SELECT * FROM Employees ORDER BY LName ASC
SELECT * FROM Employees ORDER BY LName ASC, FName ASC

-- Order by LName
SELECT Id, FName, LName, PhoneNumber FROM Employees ORDER BY 3

SELECT Id, FName, LName, PhoneNumber FROM Employees ORDER BY CASE WHEN LName='Jones' THEN 0 ELSE 1 END ASC
```

- ORDER BY com CASE

```sql
SELECT
  *
FROM
  Employee
ORDER BY
  CASE
    Department
    WHEN 'HR' THEN 1
    WHEN 'Accountant' THEN 2
    ELSE 3
  END;

-- Order by Specific Department
-- Name     Department
-- Yusuf    HR
-- Hillary  HR
-- Merry    HR
-- Ken      Accountant
-- Hasan    IT
-- Joe      IT
```

- ORDER BY alias

```sql
SELECT
  DisplayName,
  JoinDate AS jd,
  Reputation AS rep
FROM
  Users
ORDER BY
  jd,
  rep
```

---

### LIKE: operador de comparação de padrão open-ended

```sql
SELECT * FROM Employees WHERE PhoneNumber LIKE '246%'; -- seleciona todos os números de telefone que começam com 246

SELECT * FROM Employees WHERE PhoneNumber LIKE '%246'; -- seleciona todos os números de telefone que terminam com 246

SELECT * FROM Employees WHERE FName LIKE '%on%'; -- Donald, Jon, Ronny

SELECT * FROM Customers WHERE CustomerName LIKE '_r%';  -- 

SELECT * FROM Customers WHERE CustomerName LIKE 'a_%_%'; -- 

SELECT * FROM Customers WHERE ContactName LIKE 'a%o'; -- 

SELECT * FROM Employees WHERE FName LIKE '[a-g]ary'; -- range de caracteres
```