# Write your MySQL query statement below
select emp_salary.name as employee from Employee emp_salary join Employee manag_salary on emp_salary.managerId = manag_salary.id
where emp_salary.salary> manag_salary.salary