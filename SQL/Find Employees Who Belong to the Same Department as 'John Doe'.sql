Find Employees Who Belong to the Same Department as 'John Doe'.sql


SELECT * FROM employees 
WHERE 
department_id = (SELECT department_id FROM employees WHERE first_name = 'John' AND last_name = 'Doe');
