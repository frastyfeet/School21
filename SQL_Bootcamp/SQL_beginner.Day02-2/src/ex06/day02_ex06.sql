SELECT pizza_name, pizzeria.name pizzeria_name
FROM menu
JOIN person_order ON menu_id = menu.id
JOIN pizzeria ON pizzeria_id = pizzeria.id
JOIN person ON person_id = person.id
WHERE person.name = 'Denis' or person.name = 'Anna'
ORDER BY pizza_name, pizzeria.name