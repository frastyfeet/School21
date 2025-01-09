
-- 1 Сессия
BEGIN TRANSACTION ISOLATION LEVEL SERIALIZABLE;
select rating from pizzeria where name  = 'Pizza Hut';
select rating from pizzeria where name  = 'Pizza Hut';
COMMIT;
select rating from pizzeria where name  = 'Pizza Hut';

-- 2 Сессия
BEGIN TRANSACTION ISOLATION LEVEL SERIALIZABLE;
UPDATE pizzeria SET rating = 3.0 WHERE name = 'Pizza Hut';
COMMIT;
select rating from pizzeria where name  = 'Pizza Hut';