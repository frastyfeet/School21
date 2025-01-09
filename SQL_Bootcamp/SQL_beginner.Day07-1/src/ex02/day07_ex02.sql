(SELECT pi.name, COUNT(visit_date), 'visit' as action_type
FROM pizzeria pi 
JOIN person_visits  pv ON pv.pizzeria_id = pi.id
GROUP by pi.name
LIMIT 3)
UNION
(SELECT pi.name, COUNT(order_date), 'order'
FROM pizzeria pi
JOIN menu m on m.pizzeria_id = pi.id
JOIN person_order po ON po.menu_id = m.id
GROUP by pi.name
LIMIT 3)
order by 3, 2 DESC