CREATE TABLE tours (
    id BIGINT PRIMARY KEY,
  point1 VARCHAR NOT NULL,
  point2 VARCHAR NOT NULL,
  cost INT NOT NULL
  );

  INSERT INTO tours VALUES
  (1,'A','B',10);
 INSERT INTO tours VALUES
  (2,'B','A',10);
   INSERT INTO tours VALUES
  (3,'A','D',20);
     INSERT INTO tours VALUES
  (4,'D','A',20);
       INSERT INTO tours VALUES
  (5,'A','C',15);
       INSERT INTO tours VALUES
  (6,'C','A',15);
         INSERT INTO tours VALUES
  (7,'B','D',25);
         INSERT INTO tours VALUES
  (8,'D','B',25);
         INSERT INTO tours VALUES
  (9,'B','C',35);
         INSERT INTO tours VALUES
  (10,'C','B',35);
           INSERT INTO tours VALUES
  (11,'C','D',30);
             INSERT INTO tours VALUES
  (12,'D','C',30);

select * from tours;

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
),  
final_cost AS (  
  SELECT   
    r.total_cost + t.cost AS total_cost,  
    array_append(r.tour, 'A') AS tour   
  FROM r  
  JOIN tours t ON r.point2 = t.point1 AND t.point2 = 'A'  
  WHERE r.depth = 4  
)  

SELECT *  
FROM final_cost  
WHERE total_cost = (SELECT MIN(total_cost) FROM final_cost)  
ORDER BY tour; 
