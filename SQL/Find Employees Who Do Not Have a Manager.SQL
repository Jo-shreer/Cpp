
Find Employees Who Do Not Have a Manager.SQL

SELECT * 
FROM employees 
WHERE employee_id NOT IN (SELECT employee_id FROM employees WHERE manager_id IS NOT NULL);
