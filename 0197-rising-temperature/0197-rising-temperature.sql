# Write your MySQL query statement below
select new.id from Weather old join Weather new on old.recordDate = DATE_SUB(new.recordDate,INTERVAL 1 DAY)
where old.temperature<new.temperature;