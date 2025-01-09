
SELECT * FROM person_order
WHERE id % 2 = 0 and person_id % 2 = 0 and menu_id % 2 = 0 
ORDER BY id, menu_id

SELECT * FROM person_order
WHERE id % 2 = 0
ORDER BY id