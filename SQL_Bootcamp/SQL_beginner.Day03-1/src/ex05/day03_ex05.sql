SELECT DISTINCT(pizzeria.name) pizzeria_name FROM pizzeria
JOIN person_visits ON pizzeria_id = pizzeria.id
JOIN   person ON person_visits.person_id = person.id
JOIN  person_order ON person_order.person_id = person.id
JOIN menu ON person_order.menu_id = menu.id
WHERE person.name = 'Andrey' and person_visits.pizzeria_id != menu.pizzeria_id