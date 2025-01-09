CREATE UNIQUE INDEX idx_person_order_order_date on person_order(person_id,menu_id,order_date)
WHERE order_date = '2022-01-01';
SET enable_seqscan TO off;
EXPLAIN ANALYZE
SELECT * FROM person_order
WHERE person_id = 52 AND menu_id = 52 AND order_date = '2022-01-01'