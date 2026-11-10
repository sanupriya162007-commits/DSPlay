# Shell sort: insertion sort that starts by comparing values far apart (the "gap")

numbers = [8, 3, 6, 1, 5]
size = len(numbers)

gap = size // 2
while gap > 0:                                   # shrink the gap each round
    for i in range(gap, size):
        current = numbers[i]
        j = i
        while j >= gap and numbers[j - gap] > current:
            numbers[j] = numbers[j - gap]        # shift the bigger value right
            j = j - gap
        numbers[j] = current                     # drop the value in its place
    gap = gap // 2

print("Sorted:", numbers)
