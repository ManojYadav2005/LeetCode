# Write your MySQL query statement below
SELECT w.id
FROM Weather as w
LEFT JOIN Weather as w2
ON DATEDIFF(w.recordDate,w2.recordDate)=1
WHERE w.temperature>w2.temperature