# Hashing with linear probing: on a collision, check the next slot

SIZE = 7
table = [-1] * SIZE        # -1 means the slot is empty

def hash_function(key):
    return key % SIZE

def insert(key):
    index = hash_function(key)
    for i in range(SIZE):
        slot = (index + i) % SIZE       # try index, index+1, index+2 ... (wraps around)
        if table[slot] == -1:
            table[slot] = key
            print("Inserted", key, "at slot", slot)
            return
    print("Table is full")

insert(10)   # 10 % 7 = 3
insert(17)   # 17 % 7 = 3 -> collision, goes to slot 4
insert(24)   # 24 % 7 = 3 -> collision, goes to slot 5
insert(31)   # 31 % 7 = 3 -> collision, goes to slot 6
