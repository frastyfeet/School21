SELECT object_name
FROM (
    SELECT pizza_name as object_name  FROM menu
    UNION ALL
    SELECT name as object_name FROM person) as comb
    
ORDER BY 
    CASE 
        WHEN object_name IN (SELECT name FROM person) THEN 1
        ELSE 2
    END,
    object_name;
