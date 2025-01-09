
SELECT table_name
FROM information_schema.tables
WHERE table_type = 'VIEW' AND table_schema = 'public';
DROP VIEW v_price_with_discount, v_symmetric_union, v_persons_female, v_persons_male;
DROP MATERIALIZED VIEW mv_dmitriy_visits_and_eats, v_generated_dates;

SELECT table_name
FROM information_schema.tables
WHERE table_type = 'VIEW' AND table_schema = 'public';
