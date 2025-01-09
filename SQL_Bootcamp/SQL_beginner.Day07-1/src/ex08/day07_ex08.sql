SELECT p.address, pi.name, count(order_date) as count_of_orders
FROM person_order po 
JOIN person p on po.person_id = p.id
JOIN menu m ON po.menu_id = m.id
JOIN pizzeria pi ON pi.id = m.pizzeria_id
GROUP by 1,2
order by 1,2