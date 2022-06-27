-- 聚合函数结果作为筛选条件时，不能用where，而是用having语法
SELECT university,
avg(question_cnt) AS avg_question_cnt,
avg(answer_cnt) AS avg_answer_cnt
from user_profile  
GROUP BY university
HAVING avg_question_cnt  <  5  OR  avg_answer_cnt  <  20