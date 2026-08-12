# Write your MySQL query statement below
SELECT x,y,z,
(CASE WHEN ((x+y)>z && (x+z)>y && (z+y)>x) THEN 'Yes' ELSE 'No' END) AS triangle
FROM Triangle