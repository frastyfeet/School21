BEGIN; -- Начало транзакции
UPDATE pizzeria SET rating = 5 -- Обновление рейтинга с условием
WHERE name = 'Pizza Hut';
COMMIT; -- Коммит