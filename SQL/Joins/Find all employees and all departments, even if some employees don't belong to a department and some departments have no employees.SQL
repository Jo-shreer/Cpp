SELECT employees.first_name, employees.last_name, departments.department_name
FROM employees
FULL OUTER JOIN departments ON employees.department_id = departments.department_id;

Explanation:
The FULL OUTER JOIN returns all employees and all departments, filling in NULL values where there is no match.
