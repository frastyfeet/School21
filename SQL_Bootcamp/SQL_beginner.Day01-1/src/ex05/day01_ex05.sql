SELECT person.id AS "person.id",person.name AS "person.name", age,gender,address, pizzeria.id AS "pizzeria.id",
pizzeria.name AS "pizzeria.name",rating
FROM 
    person
CROSS JOIN 
    pizzeria
ORDER BY 
    person.id, person.name;