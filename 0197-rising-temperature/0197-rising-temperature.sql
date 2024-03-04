# Write your MySQL query statement below

select distinct current.id as id  from
weather current join
weather previous on current.temperature>previous.temperature and
datediff(current.recordDate,previous.recordDate)=1;