SELECT person_id, count(visit_date) as count_of_visits
FROM person_visits
GROUP by person_id
order by 2 DESC,1