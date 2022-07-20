# Write your MySQL query statement below
select (
    select distinct salary
    from Employee
    order by salary desc
    limit 1, 1
) as SecondHighestSalary;
# 要学习一下limit的用法