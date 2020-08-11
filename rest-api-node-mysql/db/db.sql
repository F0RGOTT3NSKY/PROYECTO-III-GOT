CREATE DATABASE IF NOT EXISTS company;
USE company;

CREATE TABLE employees (
	id INT(11) NOT NULL AUTO_INCREMENT,
    name VARCHAR(45) DEFAULT NULL,
    salary INT (11) DEFAULT NULL,
    PRIMARY KEY(id)
);

DESCRIBE employees;

INSERT INTO employees values
	(1, 'Marco Rivera', '20000'),
    (2, 'Adrian Gomez', '30000'),
    (3, 'Leo Guillen', '25000');
    
    -- ALTER USER 'root'@'localhost' IDENTIFIED WITH mysql_native_password BY 'M_Arcool0210';

SELECT * FROM employees;