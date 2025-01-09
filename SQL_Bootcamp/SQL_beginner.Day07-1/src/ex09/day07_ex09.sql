SELECT p.address,  CAST(ROUND(MAX(age) - MIN(age) / MAX(age::decimal), 2) as FLOAT) as formula , CAST(ROUND(avg(age::DECIMAL),2) AS FLOAT) as average, case 
											when max(age) -min(age)/MAX(age::decimal) > avg(age::DECIMAL) then 'true'
                                            else 'false'
                                            end as comparison
FROM person p
GROUP by 1
order by 1