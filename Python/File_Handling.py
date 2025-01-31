#Python can be used to read and write files. This is useful for working with data files (e.g., text files, CSVs).

# Writing to a file

with open("example.txt", "w") as file:
    file.write("Hello, Python!")


# Reading from a file
with open("example.txt", "r") as file:
    content = file.read()
    print(content)

