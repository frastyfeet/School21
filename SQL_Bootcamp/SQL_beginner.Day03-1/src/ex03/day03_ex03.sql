SELECT pizzeria.name pizzeria_name FROM pizzeria
LEFT JOIN person_visits ON pizzeria_id = pizzeria.id
LEFT JOIN person ON person.id = person_id
GROUP BY pizzeria.name
HAVING COUNT(CASE WHEN person.gender = 'female' THEN 1 END) != COUNT(CASE WHEN person.gender = 'male' THEN 1 END)
ORDER BY pizzeria.name