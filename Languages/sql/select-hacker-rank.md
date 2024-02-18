## Hackerrank

1. Consulte uma lista de nomes de CIDADES de STATION para cidades que tenham um número de identificação par. Imprima os resultados em qualquer ordem, mas exclua duplicatas da resposta.

```sql
SELECT DISTINCT
  S.city
FROM
  station AS S
WHERE
  MOD(S.id, 2) = 0
```

2. Encontre a diferença entre o número total de entradas CITY na tabela e o número de entradas CITY distintas na tabela.

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