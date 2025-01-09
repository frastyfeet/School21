SELECT person.name as person_name, menu.pizza_name as pizza_name,pizzeria.name as pizzeria_name
FROM person
JOIN pizzeria ON person.id = pizzeria.id
JOIN menu ON pizzeria_id = pizzeria.id
ORDER BY person.name, menu.pizza_name