

def sum_of_digits(n: int) -> int:
    return sum(int(digit) for digit in str(n))

# Test
print(sum_of_digits(1234))  # Output: 10
