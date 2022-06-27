-- join多表连接
select university, difficult_level, 
count(question_detail.question_id) / count(distinct(question_practice_detail.device_id))
from user_profile
join question_practice_detail 
on question_practice_detail.device_id = user_profile.device_id
join question_detail
on question_detail.question_id = question_practice_detail.question_id
group by university, difficult_level

-- where查询
select university, difficult_level, 
count(question_detail.question_id) / count(distinct(question_practice_detail.device_id))
from user_profile, question_practice_detail, question_detail
where question_practice_detail.device_id = user_profile.device_id
and question_detail.question_id = question_practice_detail.question_id
group by university, difficult_level