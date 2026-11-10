# Tower of Hanoi (recursion)
# Move n disks from rod "source" to rod "target" using rod "helper"

def hanoi(n, source, target, helper):
    if n == 0:
        return                                   # nothing to move

    hanoi(n - 1, source, helper, target)         # 1. move n-1 disks out of the way
    print("Move disk", n, "from", source, "to", target)   # 2. move the biggest disk
    hanoi(n - 1, helper, target, source)         # 3. move n-1 disks on top of it

hanoi(3, "A", "C", "B")
