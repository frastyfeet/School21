WITH RECURSIVE r AS (
  SELECT 
    point1, 
    point2, 
    cost AS total_cost, 
    ARRAY[point1, point2] AS tour,
  	2 AS depth 
  FROM tours
  WHERE point1 = 'A'
  UNION ALL
  SELECT 
    t.point1, 
    t.point2, 
    r.total_cost + t.cost AS total_cost, 
    array_append(r.tour, t.point2) AS tour,
 	r.depth + 1 AS depth  
  FROM tours t
  JOIN r ON t.point1 = r.point2
  WHERE t.point2 != ALL(r.tour)  
  AND r.depth <= 4  
)
SELECT 
  r.total_cost + t.cost AS total_cost,  
  array_append(r.tour, 'A') AS tour 
FROM r
JOIN tours t ON r.point2 = t.point1 AND t.point2 = 'A'  
WHERE r.depth = 4
ORDER BY total_cost , tour
