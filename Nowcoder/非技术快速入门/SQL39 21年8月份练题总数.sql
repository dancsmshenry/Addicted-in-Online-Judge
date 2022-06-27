select count(distinct(device_id)), count(question_id)
from question_practice_detail
where date like "2021-08%"