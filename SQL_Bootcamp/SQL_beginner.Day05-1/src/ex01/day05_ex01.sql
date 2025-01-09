SET enable_seqscan TO off;
EXPLAIN ANALYZE
SELECT pizza_name,pizzeria.name as pizzeria_name FROM pizzeria
JOIN menu ON pizzeria_id = pizzeria.id