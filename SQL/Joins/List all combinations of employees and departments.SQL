SELECT employees.first_name, departments.department_name
FROM employees
CROSS JOIN departments;


Explanation:
The CROSS JOIN produces all possible combinations of employees and departments. This could create a very large result set if the tables have many rows.
