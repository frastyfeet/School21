CREATE VIEW v_symmetric_union AS 
WITH R as
(SELECT person_id FROM person_visits pv
WHERE pv.visit_date <= '2022-01-02'),
S AS (SELECT person_id FROM person_visits pv
WHERE pv.visit_date <= '2022-01-06')

SELECT person_id FROM (SELECT * FROM R EXCEPT SELECT * FROM S) as rs
UNION 
SELECT person_id FROM (SELECT * FROM S EXCEPT SELECT * FROM R) as sr
ORDER BY person_id

SELECT * FROM v_symmetric_union