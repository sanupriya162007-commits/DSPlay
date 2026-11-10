# Hashing with separate chaining: each table slot holds a list

SIZE = 5
table = [[] for _ in range(SIZE)]   # a list of empty lists

def hash_function(key):
    return key % SIZE                # hash function: remainder

def insert(key):
    index = hash_function(key)
    table[index].append(key)         # collision? just join the list

def print_table():
    for i in range(SIZE):
        print("[" + str(i) + "]:", table[i])

insert(10)    # 10 % 5 = 0
insert(15)    # 15 % 5 = 0 -> collision, joins the list at slot 0
insert(20)    # 20 % 5 = 0 -> collision again
insert(7)     # 7 % 5 = 2
insert(12)    # 12 % 5 = 2 -> collision at slot 2
print_table()
