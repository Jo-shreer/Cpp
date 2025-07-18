Find Employees Who Have Not Taken Any Vacation.SQL

SELECT * 
FROM employees 
WHERE employee_id NOT IN (SELECT employee_id FROM vacations);
