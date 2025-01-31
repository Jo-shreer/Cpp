

def fibonacci(n: int):
    fib_sequence = [0, 1]
    for i in range(2, n):
        fib_sequence.append(fib_sequence[i-1] + fib_sequence[i-2])
    return fib_sequence[:n]

# Test
print(fibonacci(5))  # Output: [0, 1, 1, 2, 3]
