WITH persons AS (
    SELECT DISTINCT pizzeria.name as pizzeria_name, person.gender
    FROM person_order
    JOIN person ON person_order.person_id = person.id
    JOIN menu ON person_order.menu_id = menu.id
    JOIN pizzeria ON menu.pizzeria_id = pizzeria.id
)
SELECT DISTINCT pizzeria_name
FROM persons
WHERE gender = 'female'
AND pizzeria_name NOT IN (
    SELECT pizzeria_name
    FROM persons
    WHERE gender = 'male'
)
UNION
SELECT DISTINCT pizzeria_name
FROM persons
WHERE gender = 'male'
AND pizzeria_name NOT IN (
    SELECT pizzeria_name
    FROM persons
    WHERE gender = 'female'
)
ORDER BY pizzeria_name;
