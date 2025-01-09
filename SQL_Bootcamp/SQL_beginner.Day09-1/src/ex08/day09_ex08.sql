CREATE OR REPLACE FUNCTION fnc_fibonacci(pstop INTEGER DEFAULT 10)
  RETURNS SETOF INTEGER AS
$$
DECLARE
    a int := 0;
    b int := 1;
BEGIN
   RETURN NEXT 0;
   RETURN NEXT 1;
   LOOP
      a := a + b;
      EXIT WHEN a >= pstop;
      RETURN NEXT a;

      b := b + a;
      EXIT WHEN b >= pstop;
      RETURN NEXT b;
   END LOOP;
END;
$$
LANGUAGE plpgsql;

select * from fnc_fibonacci(100);
select * from fnc_fibonacci();

