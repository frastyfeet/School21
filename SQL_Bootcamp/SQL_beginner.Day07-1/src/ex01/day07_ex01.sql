SELECT name, count(visit_date) as count_of_visits
FROM person_visits
JOIN person on person_id = person.id
GROUP by name
order by 2 DESC,1
LIMIT 4