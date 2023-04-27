-- Active: 1681108504979@@127.0.0.1@3306@week11
create database week11;
CREATE TABLE t (
    val INT
);

INSERT INTO t(val)
VALUES(1),(),(2),(3),(4),(4),(5);


SELECT * FROM t;
SELECT
    val,
    RANK() OVER (
        ORDER BY val
    ) my_rank
FROM
    t;