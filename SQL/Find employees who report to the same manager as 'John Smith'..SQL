Find employees who report to the same manager as 'John Smith'..SQL

SELECT * 
FROM employees 
WHERE manager_id = (SELECT manager_id FROM employees WHERE first_name = 'John' AND last_name = 'Smith');
