SELECT pizzeria.name FROM pizzeria
JOIN menu ON pizzeria_id = pizzeria.id
JOIN person_visits ON menu.pizzeria_id = person_visits.pizzeria_id
JOIN person ON person_id = person.id
WHERE menu.price < 800 AND visit_date = '2022-01-08' AND person.name = 'Dmitriy'
