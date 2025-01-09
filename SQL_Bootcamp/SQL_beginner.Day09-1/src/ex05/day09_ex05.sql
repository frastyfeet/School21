drop FUNCTION fnc_persons_female;
drop FUNCTION fnc_persons_male;

CREATE OR REPLACE FUNCTION fnc_persons(pgender TEXT DEFAULT 'female') RETURNS SETOF person AS $$
       SELECT * FROM person
		WHERE gender = $1;
  $$
LANGUAGE sql;

select *
from fnc_persons(pgender := 'male');

select *
from fnc_persons();

