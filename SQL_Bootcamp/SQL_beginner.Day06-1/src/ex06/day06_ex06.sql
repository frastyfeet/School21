CREATE SEQUENCE seq_person_discounts
start 1;

ALTER TABLE person_discounts
ALTER COLUMN id
SET DEFAULT nextval('seq_person_discounts');

SELECT setval('seq_person_discounts', (SELECT COUNT(id) 
                                       FROM person_discounts));