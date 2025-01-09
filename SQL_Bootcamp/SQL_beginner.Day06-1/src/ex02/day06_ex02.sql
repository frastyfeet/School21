SELECT p.name, pizza_name, price, ROUND((price - price/100 * discount),0) as discount_price, pi.name as pizzeria_name
FROM person_order po
JOIN person  p on po.person_id = p.id
JOIN menu m ON  po.menu_id = m.id
join pizzeria pi on m.pizzeria_id = pi.id
join person_discounts pe ON pe.pizzeria_id = m.pizzeria_id and pe.person_id = po.person_id
ORDER by p.name, pizza_name