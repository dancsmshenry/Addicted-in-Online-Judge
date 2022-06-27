select device_id, university, gpa
from user_profile u
where gpa = 
(select min(gpa) from user_profile where u.university = user_profile.university)
order by university