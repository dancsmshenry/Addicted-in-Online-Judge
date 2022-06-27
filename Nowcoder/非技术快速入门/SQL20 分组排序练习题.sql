select university, avg(question_cnt) as avg_question_cnt
from user_profile
group by university
order by avg_question_cnt