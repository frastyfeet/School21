
-- 1 Сессия
BEGIN;
select rating from pizzeria where name  = 'Pizza Hut';
UPDATE pizzeria SET rating = 4 WHERE name = 'Pizza Hut';
COMMIT;
select rating from pizzeria where name  = 'Pizza Hut';

-- 2 Сессия
BEGIN;
select rating from pizzeria where name  = 'Pizza Hut';
UPDATE pizzeria SET rating = 3.6 WHERE name = 'Pizza Hut';
COMMIT;
select rating from pizzeria where name  = 'Pizza Hut';