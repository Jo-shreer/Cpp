SELECT * 
FROM employees 
WHERE manager_id = (SELECT manager_id FROM employees WHERE first_name = 'John' AND last_name = 'Smith');
