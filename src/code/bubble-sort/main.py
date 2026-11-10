# Bubble sort: compare neighbours and swap if they are in the wrong order

numbers = [8, 3, 6, 1, 5]
size = len(numbers)

for round_number in range(size - 1):
    for i in range(size - 1 - round_number):
        if numbers[i] > numbers[i + 1]:                 # wrong order?
            temp = numbers[i]                           # swap the two values
            numbers[i] = numbers[i + 1]
            numbers[i + 1] = temp

print("Sorted:", numbers)
