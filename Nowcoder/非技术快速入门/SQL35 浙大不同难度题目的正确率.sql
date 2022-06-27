select difficult_level, 
sum(if (result = "right", 1, 0)) / count(*) as correct_rate
from user_profile u
join question_practice_detail qu on u.device_id = qu.device_id
join question_detail q on qu.question_id = q.question_id
where university = "’„Ω≠¥Û—ß"
group by difficult_level
order by correct_rate


select difficult_level, 
sum(if (result = "right", 1, 0)) / count(*) as correct_rate
from user_profile u, question_practice_detail qu, question_detail q
where university = "????" and
u.device_id = qu.device_id and qu.question_id = q.question_id
group by difficult_level
order by correct_rate