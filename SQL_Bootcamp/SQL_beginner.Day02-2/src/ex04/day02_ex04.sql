SELECT pizza_name, pizzeria.name as pizzeria_name,price
FROM menu
JOIN pizzeria ON pizzeria_id = pizzeria.id
WHERE pizza_name = 'pepperoni pizza' OR pizza_name = 'mushroom pizza'
ORDER BY pizza_name, pizzeria.name