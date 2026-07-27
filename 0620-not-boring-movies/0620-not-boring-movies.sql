# Write your MySQL query statement below
Select * From Cinema 
WHERE id%2 =1  AND description != 'boring' 
ORDER BY  rating DESC
