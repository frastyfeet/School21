SELECT COALESCE(person.name, '-') as person_name ,date::date as visit_date, COALESCE(pizzeria.name, '-') as pizzeria_name
FROM (
    SELECT GENERATE_SERIES('2022-01-01'::timestamp, '2022-01-03', '1 day') AS date) AS new_table
LEFT JOIN person_visits ON visit_date = date::date
FULL OUTER JOIN person ON person_id = person.id
FULL OUTER JOIN pizzeria ON pizzeria.id = person_visits.pizzeria_id
ORDER BY (person.name IS NULL) DESC, person.name,visit_date,pizzeria.name;
