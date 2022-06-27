select university, difficult_level,
count(question_detail.question_id) / count(distinct(user_profile.device_id)) as avg_answer_cnt
from user_profile
join
question_practice_detail on question_practice_detail.device_id = user_profile.device_id
join
question_detail on question_detail.question_id = question_practice_detail.question_id
where university = "山东大学"
group by question_detail.difficult_level

select university, difficult_level,
count(question_detail.question_id) / count(distinct(user_profile.device_id)) as avg_answer_cnt
from user_profile, question_practice_detail, question_detail
where university = "山东大学"
and question_detail.question_id = question_practice_detail.question_id
and question_practice_detail.device_id = user_profile.device_id
group by question_detail.difficult_level