select 
if (age >= 25, '25�꼰����','25������') as age_cut,
count(device_id) as number
from user_profile
group by age_cut