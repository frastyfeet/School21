CREATE UNIQUE INDEX idx_menu_unique on menu(pizzeria_id,pizza_name);
SET enable_seqscan TO off;
EXPLAIN ANALYZE
SELECT * FROM menu
WHERE pizzeria_id = 52 AND pizza_name = 'wp'
