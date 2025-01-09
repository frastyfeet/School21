SELECT person.name FROM person
JOIN person_order ON person_id = person.id
JOIN menu ON menu_id = menu.id
WHERE pizza_name = 'pepperoni pizza' OR  pizza_name ='cheese pizza'  AND gender = 'female'
GROUP BY person.name
HAVING COUNT(DISTINCT(pizza_name)) = 2
ORDER BY person.name