SELECT departments.department_name, employees.first_name, employees.last_name
FROM employees
RIGHT JOIN departments ON employees.department_id = departments.department_id;

Explanation:
The RIGHT JOIN returns all departments, even those that do not have any employees assigned to them.
