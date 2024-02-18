## Database Employees

1. Liste o número de funcionários lotados por departamento.

```sql
SELECT
  Dep.dept_no AS departamento,
  COUNT(Emp.emp_no) AS num_employees
FROM
  employees AS Emp
  INNER JOIN dept_emp AS Dep ON Emp.emp_no = Dep.emp_no
GROUP BY
  Dep.dept_no;
```

2. Liste o número de funcionários do sexo Feminino lotados em cada departamento.

```sql
SELECT
  Dep.dept_no AS departamento,
  COUNT(Emp.emp_no) AS num_mulheres
FROM
  employees AS Emp
  INNER JOIN dept_emp AS Dep ON Emp.emp_no = Dep.emp_no
WHERE
  Emp.gender = 'F'
GROUP BY
  Dep.dept_no;
```

3. Liste o número de funcionários por função, depois separe-os por sexo “Feminino” e “Masculino”.

```sql
SELECT
  Tit.title,
  Emp.gender AS sexo,
  COUNT(Emp.emp_no) AS num_funcionarios
FROM
  employees AS Emp
  INNER JOIN titles AS Tit ON Emp.emp_no = Tit.emp_no
GROUP BY
  Tit.title,
  Emp.gender;
```

1. Liste o nome do funcionário, departamento e sua função naquele departamento.

```sql
SELECT
  Emp.first_name,
  Dep.dept_name,
  Dept.emp_no,
  Tit.title
FROM
  employees AS Emp
  INNER JOIN dept_emp AS Dept
  INNER JOIN titles AS Tit
  INNER JOIN departments Dep ON Emp.emp_no = Dept.emp_no
  AND Tit.emp_no = Emp.emp_no
  AND Dep.dept_no = Dept.dept_no;
```

5. Apresente a média do salário das funcionárias e dos funcionários.

```sql
SELECT
  Emp.gender AS genero,
  AVG(Sal.salary) AS media
FROM
  employees AS Emp
  INNER JOIN salaries AS Sal ON Emp.emp_no = Sal.emp_no
GROUP BY
  Emp.gender;
```

6. Apresente a média de salário por departamento.

```sql
SELECT
  Dept.dept_no,
  AVG(Sal.salary)
FROM
  employees AS Emp
  INNER JOIN salaries AS Sal
  INNER JOIN dept_emp AS Dept ON Emp.emp_no = Sal.emp_no
  AND Emp.emp_no = Dept.emp_no
GROUP BY
  Dept.dept_no;
```

7. Liste o nome dos funcionários que fazem aniversário no mês de julho.

```sql
SELECT
  Emp.first_name,
  Emp.birth_date
FROM
  employees AS Emp
WHERE
  EXTRACT(
    MONTH
    FROM
      Emp.birth_date
  ) = '07';
```



7. Liste o departamento que mais tem funcionários do sexo feminino alocados. Desafio!!

```sql
SELECT
  Dept.dept_no AS departamento,
  COUNT(Emp.gender) AS genero
FROM
  departments AS Dep
  INNER JOIN employees AS Emp
  INNER JOIN dept_emp AS Dept ON Dep.dept_no = Dept.dept_no
  AND Emp.emp_no = Dept.emp_no
WHERE
  Emp.gender = "F"
GROUP BY
  Dep.dept_no
ORDER BY
  Emp.gender DESC
LIMIT
  1;
```


8. Lista o nome do funcionário que tem o salário mais alto. Desafio!!

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