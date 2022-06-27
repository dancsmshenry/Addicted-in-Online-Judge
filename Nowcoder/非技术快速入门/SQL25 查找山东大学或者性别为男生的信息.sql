select device_id , gender , age , gpa from user_profile where university = '山东大学' 
UNION ALL
select device_id , gender , age , gpa from user_profile where gender = 'male'
-- 不去重要用union all，or自带去重的功能的