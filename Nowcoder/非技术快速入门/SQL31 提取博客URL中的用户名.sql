select 
device_id,
substring_index(blog_url,'/',-1) as user_name
from user_submit;