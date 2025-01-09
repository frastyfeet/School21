DROP TRIGGER trg_person_delete_audit ON person;
DROP TRIGGER trg_person_update_auditи ON person;
DROP TRIGGER trg_person_insert_audit ON person;

drop FUNCTION fnc_trg_person_insert_audit;
drop FUNCTION fnc_trg_person_update_audit;
drop FUNCTION fnc_trg_person_delete_audit;

TRUNCATE TABLE person_audit;

CREATE OR REPLACE FUNCTION fnc_trg_person_audit() RETURNS TRIGGER AS $$
    BEGIN
        IF (TG_OP = 'DELETE') THEN
            INSERT INTO person_audit (type_event,row_id, name, age, gender, address) 
   			VALUES ('D',OLD.id, OLD.name, OLD.age, OLD.gender, OLD.address);
			RETURN OLD;
        ELSIF (TG_OP = 'UPDATE') THEN
            INSERT INTO person_audit (type_event,row_id, name, age, gender, address) 
   			VALUES ('U',NEW.id, NEW.name, NEW.age, NEW.gender, NEW.address);
			RETURN NEW;
        ELSIF (TG_OP = 'INSERT') THEN
            INSERT INTO person_audit (row_id, name, age, gender, address) 
   			VALUES (NEW.id, NEW.name, NEW.age, NEW.gender, NEW.address);
			RETURN NEW;
        END IF;
        RETURN NULL;
    END;
  $$
LANGUAGE plpgsql;

CREATE TRIGGER trg_person_audit
AFTER INSERT OR UPDATE OR DELETE ON person
    FOR EACH ROW EXECUTE PROCEDURE fnc_trg_person_audit();
    
INSERT INTO person(id, name, age, gender, address)  VALUES (10,'Damir', 22, 'male', 'Irkutsk');
UPDATE person SET name = 'Bulat' WHERE id = 10;
UPDATE person SET name = 'Damir' WHERE id = 10;
DELETE FROM person WHERE id = 10;

SELECT * FROM person_audit;