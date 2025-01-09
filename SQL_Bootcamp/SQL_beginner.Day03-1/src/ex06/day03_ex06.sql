SELECT m1.pizza_name, p1.name AS pizzeria_name_1, p2.name AS pizzeria_name_2, m1.price
FROM pizzeria p1
JOIN menu m1 ON m1.pizzeria_id = p1.id
JOIN pizzeria p2 ON p1.id > p2.id
JOIN menu m2 ON m2.pizzeria_id = p2.id AND m1.pizza_name = m2.pizza_name
WHERE m1.price = m2.price
ORDER BY m1.pizza_name, m2.pizza_name;
