INSERT INTO person_visits VALUES((SELECT MAX(id) +1 FROM person_visits), (SELECT id FROM person
 WHERE name = 'Dmitriy'),(SELECT pizzeria.id FROM menu
JOIN pizzeria ON pizzeria_id = pizzeria.id
WHERE price < 800
LIMIT 1),'2022-01-08') 

REFRESH MATERIALIZED VIEW mv_dmitriy_visits_and_eats

SELECT * FROM mv_dmitriy_visits_and_eats