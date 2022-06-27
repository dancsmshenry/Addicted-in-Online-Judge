-- 这里为什么是question_id，因为这里需要的是用户的答题总数，所以不能去重
-- 用答题总数除以用户数据，就是用户的平均答题数
select university,
count(question_id) / count(distinct(question_practice_detail.device_id))
as avg_answer_cnt
from user_profile
join question_practice_detail on user_profile.device_id = question_practice_detail.device_id
group by university;


select university,
count(question_id) / count(distinct(question_practice_detail.device_id))
as avg_answer_cnt
from user_profile, question_practice_detail
where user_profile.device_id = question_practice_detail.device_id
group by university;