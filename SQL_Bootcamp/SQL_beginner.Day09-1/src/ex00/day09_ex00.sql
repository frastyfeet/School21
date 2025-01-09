CREATE TABLE person_audit (created timestamp with time zone not null default current_date,
                           type_event CHAR(1) DEFAULT 'I' constraint ch_type_event check (type_event in ('I','U','D')) ,
                           row_id BIGINT NOT NULL,
                           name VARCHAR,
                           age integer default 10,
                           gender varchar default 'female',
                           address VARCHAR);
                           
CREATE OR REPLACE FUNCTION fnc_trg_person_insert_audit()
  RETURNS trigger AS
$$
BEGIN
 	INSERT INTO person_audit (row_id, name, age, gender, address) 
    VALUES (NEW.id, NEW.name, NEW.age, NEW.gender, NEW.address);
	RETURN NEW;
END;
$$
LANGUAGE 'plpgsql';
CREATE TRIGGER trg_person_insert_audit
  AFTER INSERT
  ON person
  FOR EACH ROW
  EXECUTE PROCEDURE fnc_trg_person_insert_audit();
  
  INSERT INTO person(id, name, age, gender, address) VALUES (10,'Damir', 22, 'male', 'Irkutsk');
  
  SELECT * FROM person_audit; 
  

