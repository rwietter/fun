-- CREATE TABLE medico (
--     cod_med int NOT NULL AUTO_INCREMENT,
--     cremers int,
--     nome varchar(60),
--     idade int,
--     PRIMARY KEY (`cod_med`)
-- );

-- CREATE TABLE paciente (
--     cod_pac int NOT NULL AUTO_INCREMENT,
--     nome varchar(60),
--     idade int,
--     endereco varchar(60),
--     prontuario varchar(200),
--     PRIMARY KEY (`cod_pac`)
-- );

-- CREATE TABLE consulta (
--     cod_med int,
--     cod_pac int,
--     data_hora Datetime,
--     setor varchar(10),
--     sala varchar(10),
--     FOREIGN KEY (cod_med) REFERENCES medico (cod_med) ON DELETE RESTRICT ON UPDATE CASCADE,
--     FOREIGN KEY (cod_pac) REFERENCES paciente (cod_pac) ON DELETE RESTRICT ON UPDATE CASCADE
-- );

-- INSERT INTO medico (cremers, nome, idade)
-- VALUES (123, "Mauricio", 24);
-- INSERT INTO medico (cremers, nome, idade)
-- VALUES (456, "Tiago", 30);
-- INSERT INTO medico (cremers, nome, idade)
-- VALUES (789, "Douglas", 55);

-- INSERT INTO paciente (nome, idade, endereco, prontuario)
-- VALUES ("Lucas", 20, "Frederico Wesphalen", "Receita de remedios");
-- INSERT INTO paciente (nome, idade, endereco, prontuario)
-- VALUES ("Victor", 27, "Constantina", "Receita de antibiótico");
-- INSERT INTO paciente (nome, idade, endereco, prontuario)
-- VALUES ("Mateus", 20, "Novo Xingu", "Receita de pomada");

-- INSERT INTO consulta (cod_med, cod_pac, data_hora, setor, sala)
-- VALUES (1, 1, "2022-10-06 20:00:00", "A", "1");
-- INSERT INTO consulta (cod_med, cod_pac, data_hora, setor, sala)
-- VALUES (NULL, 	NULL, "2022-10-06 20:00:00", "A", "1");

-- INNER JOIN: traz os dados da tabela direita e esquerda quando os valores não forem nulos e existirem na comparação
SELECT DISTINCT
    *
FROM
    paciente AS p
        INNER JOIN
    consulta AS c ON p.cod_pac = c.cod_pac;

-- LEFT JOIN: traz os dados da tabela da esquerda e da interseção da direita mesmo que sejam nulos
SELECT DISTINCT
    *
FROM
    paciente AS p
        LEFT OUTER JOIN
    consulta AS c ON p.cod_pac = c.cod_pac;


-- RIGHT JOIN: traz os dados da tabela a direita e da interseção mesmo que sejam nulos
SELECT DISTINCT
    *
FROM
    paciente AS p
        RIGHT OUTER JOIN
    consulta AS c ON p.cod_pac = c.cod_pac;

-- Agrupar nomes e contar quanto nomes tem em cada grupo de nome
SELECT 
    C.nome, COUNT(C.nome)
FROM
    paciente AS C
GROUP BY C.nome;

-- SELECT apenas nulos
SELECT 
    *
FROM
    paciente AS P
        LEFT JOIN
    consulta AS C ON C.cod_pac = P.cod_pac
WHERE
    C.cod_med IS NULL;


-- SELECT apenas NÃO nulos
SELECT 
    *
FROM
    paciente AS P
        LEFT JOIN
    consulta AS C ON C.cod_pac = P.cod_pac
WHERE
    C.cod_med IS NOT NULL -- equivalente ao INNER JOIN

