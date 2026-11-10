# Merge two sorted runs into one sorted list
# (Multiway / polyphase merge repeat this idea with more runs)

a = [1, 4, 7]
b = [2, 5, 6]
result = []
i = 0
j = 0

while i < len(a) and j < len(b):      # pick the smaller front value
    if a[i] <= b[j]:
        result.append(a[i])
        i += 1
    else:
        result.append(b[j])
        j += 1

while i < len(a):                     # copy what is left in a
    result.append(a[i])
    i += 1
while j < len(b):                     # copy what is left in b
    result.append(b[j])
    j += 1

print("Merged:", result)
