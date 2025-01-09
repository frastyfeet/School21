-- 1 Сессия
BEGIN;
SELECT SUM(rating) FROM pizzeria;
SELECT SUM(rating) FROM pizzeria;
COMMIT;
SELECT SUM(rating) FROM pizzeria;

-- 2 Сессия
BEGIN;
INSERT INTO pizzeria VALUES(10,'Kazan Pizza',5);
COMMIT;
SELECT SUM(rating) FROM pizzeria;