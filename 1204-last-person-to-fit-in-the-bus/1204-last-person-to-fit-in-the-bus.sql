# Write your MySQL query statement below
SELECT a.person_name
FROM Queue a
JOIN Queue b
ON b.turn<=a.turn

GROUP BY a.person_id,a.person_name,a.turn
HAVING SUM(b.weight)<=1000
ORDER BY a.turn DESC
LIMIT 1;
