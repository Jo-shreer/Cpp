SELECT employees.first_name, employees.last_name, departments.department_name
FROM employees
LEFT JOIN departments ON employees.department_id = departments.department_id;


Explanation:

The LEFT JOIN returns all employees, even those who do not belong to any department (i.e., those whose department_id is NULL in the departments table).
