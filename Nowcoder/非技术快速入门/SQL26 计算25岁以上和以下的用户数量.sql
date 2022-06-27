select 
if (age >= 25, '25岁及以上','25岁以下') as age_cut,
count(device_id) as number
from user_profile
group by age_cut