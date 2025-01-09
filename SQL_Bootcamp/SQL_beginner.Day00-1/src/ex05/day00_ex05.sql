SELECT 
    (SELECT  p.name FROM person as p 
     WHERE 
        p.id = o.person_id
    ) AS NAME
FROM 
    person_order as o
WHERE 
    (o.menu_id = 13 or o.menu_id = 14 or o.menu_id = 18) 
    AND o.order_date = '2022-01-07'
