-- 1 Сессия
BEGIN;
UPDATE pizzeria SET rating = 3.3 WHERE id = 1;
UPDATE pizzeria SET rating = 3.5 WHERE id = 2;
COMMIT;

-- 2 Сессия
BEGIN;
UPDATE pizzeria SET rating = 3.3 WHERE id = 2;
UPDATE pizzeria SET rating = 3.5 WHERE id = 1;
COMMIT;