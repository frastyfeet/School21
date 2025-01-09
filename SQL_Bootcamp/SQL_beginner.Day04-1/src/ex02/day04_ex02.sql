CREATE MATERIALIZED VIEW v_generated_dates AS
SELECT date::date AS generated_date
FROM GENERATE_SERIES('2022-01-01'::date, '2022-01-31'::date, '1 day'::interval) AS date;