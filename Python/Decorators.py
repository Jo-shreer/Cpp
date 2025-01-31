#A decorator is a function that modifies the behavior of another function.
#It's often used for logging, timing, or checking permissions.

# Simple decorator example

def decorator(func):
    def wrapper():
        print("Before the function call")
        func()
        print("After the function call")
    return wrapper

@decorator
def say_hello():
    print("Hello!")

say_hello()  # This will print the decorator’s added behavior along with the function’s output
