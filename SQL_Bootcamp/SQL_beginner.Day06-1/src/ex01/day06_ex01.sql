INSERT INTO person_discounts SELECT ROW_NUMBER() OVER(ORDER by person_id, pizzeria_id) as id, 
                                    person_id, pizzeria_id,
                                    CASE
                                    	when COUNT(person_id) = 1 then 10.5  
                                    	when COUNT(person_id) = 2 then 22 
                                    	else  30
                                    END AS discount
                                    FROM person_order
                                    JOIN menu on menu_id = menu.id
                                    GROUP BY 2,3
                                    
                                    
                                  
;
                                    
                                    
 