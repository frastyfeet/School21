CREATE INDEX idx_person_name  ON person(UPPER(name));
SET enable_seqscan TO off;
EXPLAIN
SELECT * FROM person WHERE UPPER(name) = 'Denis';