"""
Iterators are objects that allow you to traverse through all the elements of a collection.
#Generators are functions that return an iterable set of items, one at a time, using the yield keyword.
"""
Simple iterator example

numbers = [1, 2, 3]
it = iter(numbers)  # Creating an iterator
print(next(it))  # Output: 1
print(next(it))  # Output: 2

# Generator example
def count_up_to(limit):
    count = 1
    while count <= limit:
        yield count
        count += 1

counter = count_up_to(5)
for num in counter:
    print(num)  # Prints numbers 1 through 5
