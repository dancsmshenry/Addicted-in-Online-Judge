select device_id, gender, 
case
    when age < 20 then '20������'
    when age < 25 then '20-24��'
    when age >= 25 then '25�꼰����'
    else '����'
end age_cut
from user_profile