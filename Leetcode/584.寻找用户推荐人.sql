# Write your MySQL query statement below
select name
from customer
# where referee_id != 2 or referee_id is NULL;
where referee_id is NULL or referee_id != 2;