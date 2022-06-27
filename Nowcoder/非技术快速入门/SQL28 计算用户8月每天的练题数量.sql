select day(date) as day, count(question_id) as question_cnt
from question_practice_detail
where date like "2021-08%"
group by day(date)