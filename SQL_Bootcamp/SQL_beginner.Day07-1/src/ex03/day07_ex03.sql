WITH visits AS (
    SELECT pi.name, COUNT(visit_date) AS visit_count
    FROM pizzeria pi
    JOIN person_visits pv ON pv.pizzeria_id = pi.id
    GROUP BY pi.name
),
orders AS (
    SELECT pi.name, COUNT(order_date) AS order_count
    FROM pizzeria pi
    JOIN menu m ON m.pizzeria_id = pi.id
    JOIN person_order po ON po.menu_id = m.id
    GROUP BY pi.name
)
SELECT COALESCE(v.name, o.name) AS name, COALESCE(visit_count, 0) + COALESCE(order_count, 0) AS total_count
FROM visits v
FULL JOIN orders o ON v.name = o.name
ORDER BY total_count DESC, name;
