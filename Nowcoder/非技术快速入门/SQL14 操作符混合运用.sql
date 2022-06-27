select device_id, gender, age, university, gpa
from user_profile
where (gpa > 3.5 and university = "山东大学") or 
(gpa > 3.8 and university = "复旦大学");