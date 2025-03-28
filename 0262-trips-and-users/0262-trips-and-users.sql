# Write your MySQL query statement below
SELECT 
    request_at AS Day,
    ROUND(
        SUM(CASE WHEN STATUS != 'completed' THEN 1 ELSE 0 END) / COUNT(*), 
        2
    ) AS `Cancellation Rate`
FROM 
    trips t
JOIN 
    users u1 
    ON t.client_id = u1.users_id 
    AND u1.banned = 'No'
JOIN 
    users u2 
    ON t.driver_id = u2.users_id 
    AND u2.banned = 'No'
WHERE 
    request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY 
    request_at;