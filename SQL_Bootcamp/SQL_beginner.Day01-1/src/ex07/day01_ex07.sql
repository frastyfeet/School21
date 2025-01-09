SELECT action_date as order_date, CONCAT(person.name, '(age:',person.age,')') as "person_information"
FROM (
    SELECT order_date AS action_date, person_id
    FROM person_order
) AS combined
JOIN person on combined.person_id = person.id

ORDER BY action_date,person.name;