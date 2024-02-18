<div align="center">
    <h2>Funções de agregação</h2>
</div> 

---

### Funções de agregação

### COUNT: contador de ocorrências [de um atributo].

```sql
SELECT
  (
    SELECT
      COUNT(S.city)
    FROM
      station AS S
  ) - (
    SELECT
      COUNT(DISTINCT S.city)
    FROM
      station AS S
  ) AS cities
FROM
  station
GROUP BY
  cities;
```

### SUM: soma de valores.

```sql
SELECT
  Emp.first_name,
  Sal.salary
FROM
  employees AS Emp
  INNER JOIN salaries AS Sal ON Emp.emp_no = Sal.emp_no
WHERE
  Sal.salary = (
    SELECT
      SUM(Sal.salary)
    FROM
      salaries AS Sal
  );
```

### MAX: maior valor.

```sql
SELECT
  Emp.first_name,
  Sal.salary
FROM
  employees AS Emp
  INNER JOIN salaries AS Sal ON Emp.emp_no = Sal.emp_no
WHERE
  Sal.salary = (
    SELECT
      MAX(Sal.salary)
    FROM
      salaries AS Sal
  );
```

### MIN: menor valor.

```sql
SELECT
  Emp.first_name,
  Sal.salary
FROM
  employees AS Emp
  INNER JOIN salaries AS Sal ON Emp.emp_no = Sal.emp_no
WHERE
  Sal.salary = (
    SELECT
      MIN(Sal.salary)
    FROM
      salaries AS Sal
  );
```

### AVG: média de valores.

```sql
SELECT
  Emp.gender AS genero,
  AVG(Sal.salary) AS media
FROM
  employees AS Emp
  INNER JOIN salaries AS Sal ON Emp.emp_no = Sal.emp_no
GROUP BY
  Emp.gender;

-- Media Average from department where department is different of the 'ACCOUNTING'
SELECT department, AVG(income) FROM employees WHERE department <> 'ACCOUNTING' GROUP BY department;


-- Filter departaments with average income greater than 10000
SELECT department, AVG(income) FROM employees WHERE department <> 'ACCOUNTING' GROUP BY department HAVING avg(income) > 1000;
```