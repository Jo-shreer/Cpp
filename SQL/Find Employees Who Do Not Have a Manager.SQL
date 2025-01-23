SELECT * 
FROM employees 
WHERE employee_id NOT IN (SELECT employee_id FROM employees WHERE manager_id IS NOT NULL);
