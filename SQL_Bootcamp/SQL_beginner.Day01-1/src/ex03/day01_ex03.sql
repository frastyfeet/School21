SELECT action_date, person_id
FROM (
    SELECT order_date AS action_date, person_id
    FROM person_order
    UNION ALL
    SELECT visit_date AS action_date, person_id
    FROM person_visits
) AS combined
GROUP BY action_date, person_id
HAVING COUNT(*) > 1
ORDER BY action_date, person_id DESC;