alter TABLE person_discounts 
ADD CONSTRAINT ch_nn_person_id
check(person_id IS NOT NULL);

alter TABLE person_discounts 
ADD CONSTRAINT ch_nn_pizzeria_id
check(pizzeria_id IS NOT NULL);

alter TABLE person_discounts 
ADD CONSTRAINT ch_nn_discount
check(discount IS NOT NULL);

ALTER TABLE person_discounts 
ALTER COLUMN discount 
SET DEFAULT 0;

alter TABLE person_discounts 
ADD CONSTRAINT ch_range_discount
CHECK (discount >= 0 AND discount <= 100);


