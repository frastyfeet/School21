SELECT person_id
FROM (
        SELECT person_id
        FROM person_order
        WHERE order_date = '2022-01-07'
        except ALL
        SELECT person_id
        FROM person_visits
        WHERE visit_date = '2022-01-07'
    ) as diff
UNION ALL
SELECT person_id
FROM (
        SELECT person_id
        FROM person_visits
        WHERE visit_date = '2022-01-07'
        except ALL
        SELECT person_id
        FROM person_order
        WHERE order_date = '2022-01-07'
    ) as diff2
ORDER BY person_id