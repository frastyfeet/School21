SELECT pizza_name,price, pizzeria.name as pizzeria_name, visit_date FROM menu
JOIN pizzeria ON menu.pizzeria_id = pizzeria.id
JOIN person_visits ON pizzeria.id = person_visits.pizzeria_id
JOIN person ON person.id = person_visits.person_id
WHERE person.name = 'Kate' and price BETWEEN 800 and 1000 
ORDER BY pizza_name, price, pizzeria.name