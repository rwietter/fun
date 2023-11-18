SET character_set_client = utf8;
SET character_set_connection = utf8;
SET character_set_results = utf8;
SET collation_connection = utf8_general_ci;

CREATE USER 'devbook'@'localhost' IDENTIFIED BY '123456';

CREATE database devbook;

GRANT ALL PRIVILEGES ON devbook.* TO 'devbook'@'%' IDENTIFIED BY '123456';
FLUSH PRIVILEGES;

USE devbook;

CREATE TABLE users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    email VARCHAR(100) NOT NULL,
    password VARCHAR(255) NOT NULL,
) ENGINE=InnoDB;

-- mysql -uroot -p