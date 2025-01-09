SELECT pizza_name,price, pizzeria.name pizzeria_name FROM menu
JOIN pizzeria ON menu.pizzeria_id = pizzeria.id
LEFT JOIN person_order ON menu.id = person_order.menu_id
WHERE order_date is NULL
ORDER BY pizza_name, price