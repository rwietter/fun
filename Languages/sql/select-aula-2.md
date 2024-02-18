1. Informe os dados dos Médicos e suas Especialidades. Utilize o comando JOIN.

```sql
SELECT
  espec,
  nome
FROM
  med_espec AS MedEsp
  INNER JOIN especialidade AS Esp ON MedEsp.cod_espec = Esp.cod_espec
  INNER JOIN medico AS Me ON Me.cod_med = MedEsp.cod_med;
-- > | cardiologista | Dermatologista | Pediatra |
-- > |    Maria      |     João       |   João   |
-- > |               |                |   José   |
```

2. Informe os dados dos funcionários que trabalham no setor A. Utilize subconsulta.

```sql
SELECT
  *
FROM
  funcionario AS Fn
WHERE
  Fn.setor = (
    SELECT
      MIN(setor)
    FROM
      funcionario
  );
-- > Pedro e Ana
```

3. Liste o nome dos médicos que não são pediatras.

```sql
SELECT
  nome
FROM
  medico AS Med
  INNER JOIN med_espec AS MedEsp
  INNER JOIN especialidade AS Esp ON Med.cod_med = MedEsp.cod_med
  AND Esp.cod_espec = MedEsp.cod_espec
  AND Esp.espec <> 'pediatra';
-- > Maria e (João)
```

4. Informe os dados dos funcionários com idade menor que 50 anos e salário superior a R$ 1.000,00.

```sql
SELECT
  *
FROM
  funcionario
WHERE
  idade < 50
  AND salario > 1000;
-- > Marcos (1500) | Ana (2000) | Lucas (2500)
```

5. Informe os nomes dos médicos que são pediatras. Utilize o comando JOIN

```sql
SELECT
  nome
FROM
  medico AS Med
  INNER JOIN med_espec AS MedEsp ON MedEsp.cod_med = Med.cod_med
  INNER JOIN especialidade AS Esp ON Esp.cod_espec = MedEsp.cod_espec
  AND Esp.espec = 'pediatra';
-- > josé e joão
```

6. Informe os nomes das especialidades do médico de nome João. Utilize o comando JOIN.

```sql
SELECT
  nome,
  espec
FROM
  medico AS M
  INNER JOIN med_espec AS ME ON ME.cod_med = M.cod_med
  INNER JOIN especialidade AS ES ON ME.cod_espec = ES.cod_espec
  AND M.nome = 'João';
-- dermatologista e pediatra
```

7. Quais os nomes dos médicos que começam com a letra J? Apresente-os em ordem alfabética.

```sql
SELECT
  nome
FROM
  medico AS Med
WHERE
  Med.nome LIKE 'J%'
ORDER BY
  Med.nome ASC;
-- > João, José
```

8. Quais os diferentes nomes dos médicos que atenderam o paciente Rafael? Utilize o comando JOIN.

```sql
INSERT INTO
  consulta (cod_med, cod_pac, data_hora, setor, sala)
VALUES
  (1, 3, '2022-10-29', 'A', 5);
-- Maria -> consulta <- Rafael

INSERT INTO
  consulta (cod_med, cod_pac, data_hora, setor, sala)
VALUES
  (2, 4, '2022-09-26', 'B', 2);
-- João -> consulta <- André


SELECT
  DISTINCT Med.nome
FROM
  medico AS Med
  INNER JOIN consulta AS Cons ON Med.cod_med = Cons.cod_med
  INNER JOIN paciente AS Pac ON Pac.cod_pac = Cons.cod_pac
  AND Pac.nome = 'Rafael';
-- > Maria
```

9. Quais os nomes dos pacientes que tiveram consultas no dia 31 de julho de 2013? Utilize subconsulta

```sql
INSERT INTO
  consulta (cod_med, cod_pac, data_hora, setor, sala)
VALUES
  (3, 1, '2013-01-10', 'A', 1);
-- José -> consulta <- Patrícia

INSERT INTO
  consulta (cod_med, cod_pac, data_hora, setor, sala)
VALUES
  (3, 2, '2013-08-10', 'A', 1);
-- José -> consulta <- Priscila

INSERT INTO
  consulta (cod_med, cod_pac, data_hora, setor, sala)
VALUES
  (3, 2, '2013-07-31', 'A', 1);
-- José -> consulta <- Priscila

SELECT
  DISTINCT Pac.nome,
  DATE(Cons.data_hora) AS data
FROM
  paciente AS Pac
  INNER JOIN consulta AS Cons ON Pac.cod_pac = Cons.cod_pac
WHERE
  DATE(Cons.data_hora) IN (
    SELECT
      DISTINCT DATE(Cons.data_hora)
    FROM
      consulta AS Cons
    WHERE
      Cons.data_hora LIKE '%2013-07-31%'
  );
-- > Priscila 2013-07-31
```

10. Quais os nomes dos pacientes que se consultaram com a médica Maria? Utilize subconsulta.

```sql
SELECT
  DISTINCT Pac.nome
FROM
  paciente AS Pac
  INNER JOIN (
    SELECT
      *
    FROM
      consulta
  ) AS Cons ON Pac.cod_pac = Cons.cod_pac
  INNER JOIN (
    SELECT
      *
    FROM
      medico
  ) AS Med ON Cons.cod_med = Med.cod_med
WHERE
  Med.nome = 'Maria';
-- Maria consultou Rafael
```

11. Informe o médico com menor idade. Use subconsulta.

```sql
SELECT
  *
FROM
  medico AS Med
WHERE
  Med.idade = (
    SELECT
      MIN(Med.idade)
    FROM
      medico AS Med
  );
-- > Maria tem menor idade = 24
```

12. Informe o nome do funcionário que tem o menor salário. Use subconsulta

```sql
SELECT
  nome, salario
FROM
  funcionario AS Fun
WHERE
  Fun.salario = (
    SELECT
      MIN(Fun.salario)
    FROM
      funcionario AS Fun
  );
-- > Pedro tem o menor salário = R$ 500
```

13. Liste o nome do médico e o total de especialidades que ele tem.

```sql
SELECT
  Med.nome,
  COUNT(Esp.espec)
FROM
  medico AS Med
  INNER JOIN med_espec AS MedEsp ON Med.cod_med = MedEsp.cod_med
  INNER JOIN especialidade AS Esp ON Esp.cod_espec = MedEsp.cod_espec
GROUP BY
  Med.nome
ORDER BY
  COUNT(Esp.espec) DESC;

-- | João | Maria | José |
-- |  2   |   1	  |   1  |
```

14. Liste o nome do paciente e o total de consultas marcadas.

```sql
SELECT
  Pac.nome,
  COUNT(Cons.cod_pac) AS Consultas
FROM
  paciente AS Pac
  INNER JOIN consulta AS Cons ON Pac.cod_pac = Cons.cod_pac
GROUP BY
  Pac.nome
ORDER BY
  COUNT(Cons.cod_pac) DESC;

-- | André | Rafael | Patricia | Priscila |
-- |  6    |   6	|    6     |    8     |
```

15. Liste o nome do médico e o total de consultas marcadas.

```sql
SELECT
  Med.nome,
  COUNT(Cons.cod_med) AS Consultas
FROM
  medico AS Med
  INNER JOIN consulta AS Cons ON Med.cod_med = Cons.cod_med
GROUP BY
  Med.nome
ORDER BY
  COUNT(Cons.cod_med) DESC;

-- | José | Maria | João |
-- |  14  |   6	  |  6   |
```

---

### Select wildcard with dot notation

Geralmente é aconselhado que o uso * seja evitado no código de produção sempre que possível, pois pode causar vários problemas em potencial, incluindo:
- Excesso de IO, carga de rede, uso de memória.

Podemos utilizar em alguns casos como subselect:
- Quando utilizamos EXISTS, como selecionar `SELECT A.col1, A.Col2 FROM A WHERE EXISTS (SELECT * FROM B where A.ID = B.A_ID)`, não estamos retornando nenhum dado de B.

```sql
SELECT 
    Employees.*, Departments.Name
FROM
    Employees JOI
```