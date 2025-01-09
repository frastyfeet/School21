SELECT p1.name as person_name1, p2.name as person_name2, p1.address as common_address
FROM person p1
JOIN person p2 ON p1.address = p2.address AND p2.id < p1.id
WHERE p1.address is NOT NULL
ORDER BY p1.name, p2.name, p1.address