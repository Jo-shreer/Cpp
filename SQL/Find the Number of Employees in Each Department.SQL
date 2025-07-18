Find the Number of Employees in Each Department.SQL


SELECT department_id, COUNT(*) AS employee_count
FROM employees
GROUP BY department_id;
