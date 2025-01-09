COMMENT on TABLE person_discounts is 'Таблица размеров скидки каждого покупателя';

COMMENT on COLUMN person_discounts.id is 'ID person_discounts';

COMMENT ON COLUMN person_discounts.person_id IS 'ID person';

COMMENT ON COLUMN person_discounts.pizzeria_id IS 'ID pizzeria';

COMMENT ON COLUMN person_discounts.discount IS 'Процент Скидки';
