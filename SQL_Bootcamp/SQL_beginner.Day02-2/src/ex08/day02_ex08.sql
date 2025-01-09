SELECT person.name FROM person
JOIN person_order ON person_id = person.id
JOIN menu ON menu_id = menu.id
WHERE pizza_name IN('pepperoni pizza','mushroom pizza') AND address IN('Moscow', 'Samara') AND gender = 'male'
ORDER BY person.name DESC
