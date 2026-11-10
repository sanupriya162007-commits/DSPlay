# Linear search: check every value one by one

numbers = [8, 3, 6, 1, 5]
target = 6
found = -1                         # -1 means "not found yet"

for i in range(len(numbers)):
    if numbers[i] == target:       # compare each value with the target
        found = i
        break

if found != -1:
    print("Found", target, "at index", found)
else:
    print(target, "not found")
