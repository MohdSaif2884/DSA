# Write your MySQL query statement below

SELECT Employee.name , Bonus.bonus
from Employee LEFT JOIN Bonus
ON Employee.empId = Bonus.empId
where bonus <1000 or Bonus is NULL
