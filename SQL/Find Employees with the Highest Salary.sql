Find Employees with the Highest Salary.sql


SELECT * FROM employees 
WHERE salary = (SELECT MAX(salary) FROM employees);
