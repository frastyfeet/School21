SELECT p.name, COUNT(visit_date) as count_of_visits
FROM person_visits pv
JOIN person p ON pv.person_id = p.id
GROUP by 1
HAVING COUNT(visit_date) > 3