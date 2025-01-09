SELECT order_date, CONCAT(p.name, '(age:',p.age,')') as "person_information"
FROM person_order
NATURAL JOIN person p(person_id)
ORDER BY order_date,person_information;