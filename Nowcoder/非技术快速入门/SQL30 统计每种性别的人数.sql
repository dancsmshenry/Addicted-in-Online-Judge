select substring_index(profile,',',-1) as gender, count(device_id) as number
from user_submit
group by gender