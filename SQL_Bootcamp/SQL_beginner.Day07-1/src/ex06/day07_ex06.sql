SELECT pi.name, COUNT(order_date), round(avg(price)),max(price),MIN(price)
FROM menu m
JOIN person_order po on po.menu_id = m.id
JOIN pizzeria pi ON m.pizzeria_id = pi.id
GROUP by 1
order by 1