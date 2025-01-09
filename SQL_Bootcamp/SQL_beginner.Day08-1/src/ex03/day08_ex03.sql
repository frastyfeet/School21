
-- 1 Сессия
BEGIN TRANSACTION ISOLATION LEVEL READ COMMITTED;
select rating from pizzeria where name  = 'Pizza Hut';
select rating from pizzeria where name  = 'Pizza Hut';
COMMIT;
select rating from pizzeria where name  = 'Pizza Hut';

-- 2 Сессия
BEGIN TRANSACTION ISOLATION LEVEL READ COMMITTED;
UPDATE pizzeria SET rating = 3.6 WHERE name = 'Pizza Hut';
COMMIT;
select rating from pizzeria where name  = 'Pizza Hut';