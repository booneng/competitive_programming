with open('1.out', 'r') as f:
    l1 = f.read()
with open('2.out', 'r') as f:
    l2 = f.read()
print(l1 == l2)
