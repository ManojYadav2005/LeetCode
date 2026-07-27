# Write your MySQL query statement below
SELECT unique_id,name
FROM Employees as e
LEFT JOIN EmployeeUNI as en
ON e.id=en.id
