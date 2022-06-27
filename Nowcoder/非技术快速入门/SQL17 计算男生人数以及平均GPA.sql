select count(id) as male_num,avg(gpa) as avg_gpa
from user_profile
where gender = "male"