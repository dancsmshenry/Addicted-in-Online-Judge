-- ����Ϊʲô��question_id����Ϊ������Ҫ�����û��Ĵ������������Բ���ȥ��
-- �ô������������û����ݣ������û���ƽ��������
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