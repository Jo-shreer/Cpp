#You can handle errors in Python using try and except blocks, which allows you to catch exceptions and prevent your program from crashing.

# Example of error handling
try:
    result = 10 / 0  # This will raise an exception (division by zero)
  
except ZeroDivisionError:
    print("Cannot divide by zero!")
