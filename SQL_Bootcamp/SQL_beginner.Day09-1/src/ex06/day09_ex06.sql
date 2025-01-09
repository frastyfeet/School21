
CREATE FUNCTION fnc_person_visits_and_eats_on_date(pperson VARCHAR DEFAULT 'Dmitriy', pprice NUMERIC DEFAULT 500, pdate date DEFAULT '2022-01-08') 
RETURNS TABLE(pizzeria_name VARCHAR) AS $$
BEGIN
RETURN QUERY
   SELECT DISTINCT pi.name AS pizzeria_name FROM pizzeria pi
   JOIN menu m on m.pizzeria_id = pi.id
   JOIN person_visits pv on pv.pizzeria_id = pi.id
   JOIN person p on pv.person_id = p.id
   WHERE p.name = pperson
         AND m.price < pprice
         AND pv.visit_date = pdate;
END;
$$ LANGUAGE plpgsql;

select *
from fnc_person_visits_and_eats_on_date(pprice := 800);

select *
from fnc_person_visits_and_eats_on_date(pperson := 'Anna',pprice := 1300,pdate := '2022-01-01');
