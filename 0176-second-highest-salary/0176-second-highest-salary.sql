# Write your MySQL query statement below
select distinct max(salary)  as SecondHighestSalary from employee
where salary<(select distinct max(salary) from employee);
