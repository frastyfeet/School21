CREATE VIEW v_price_with_discount AS
SELECT name, pizza_name, price, ROUND(price - price*0.1,0) as discount_price
FROM menu
JOIN person_order ON menu_id = menu.id
JOIN person ON person.id = person_id 
ORDER BY person.name,pizza_name