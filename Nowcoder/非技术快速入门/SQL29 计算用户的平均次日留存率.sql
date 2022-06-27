select count(t2.date)/count(t1.date) from
    (select distinct device_id,date from question_practice_detail) t1
    left join 
    (select distinct device_id,date from question_practice_detail) t2
    on t1.device_id = t2.device_id 
    and t2.date = date_add(t1.date,interval 1 day) 