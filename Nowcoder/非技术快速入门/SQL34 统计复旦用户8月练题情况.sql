select q.device_id, university,
count(question_id) as question_cnt, 
sum( if(result='right',1,0) ) as right_question_cnt
from user_profile u left join question_practice_detail q on q.device_id = u.device_id
where u.university='∏¥µ©¥Û—ß' and q.date like '%-08%'
group by u.device_id