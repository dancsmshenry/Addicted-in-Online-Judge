-- ????
select user_profile.device_id, question_id ,result
from question_practice_detail, user_profile
where university = "????"
and question_practice_detail.device_id = user_profile.device_id


-- ???
select device_id, question_id, result
from question_practice_detail
where device_id = (
    select device_id
    from user_profile
    where university = "????"
)