#These functions allow you to process lists in a functional programming style.

map(): Applies a function to every item in an iterable.
filter(): Filters the iterable based on a condition.
reduce(): Reduces an iterable to a single value using a function.
__________________________________________________________________________
from functools import reduce

# map example
numbers = [1, 2, 3, 4]
squared = list(map(lambda x: x**2, numbers))
print(squared)

# filter example
even_numbers = list(filter(lambda x: x % 2 == 0, numbers))
print(even_numbers)

# reduce example (calculating the product of all elements)
product = reduce(lambda x, y: x * y, numbers)
print(product)
