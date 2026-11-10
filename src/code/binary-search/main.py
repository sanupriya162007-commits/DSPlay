# Binary search: the list MUST be sorted

numbers = [1, 3, 6, 8, 10]
target = 8

low = 0                       # start of the search range
high = len(numbers) - 1       # end of the search range
found = -1

while low <= high:
    mid = (low + high) // 2             # look at the middle value
    if numbers[mid] == target:
        found = mid
        break
    elif numbers[mid] < target:
        low = mid + 1                   # target is in the right half
    else:
        high = mid - 1                  # target is in the left half

if found != -1:
    print("Found", target, "at index", found)
else:
    print(target, "not found")
