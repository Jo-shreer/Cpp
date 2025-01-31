#Python is an object-oriented programming (OOP) language, so you can define classes and create objects.

# Defining a class
class Dog:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def bark(self):
        return f"{self.name} says Woof!"

# Creating an object
my_dog = Dog("Buddy", 3)
print(my_dog.bark())  # Calling a method on the object
