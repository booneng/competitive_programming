import random

T = 100
M = 100
G = 100

print T
for _ in xrange(T):
    print M
    for i in xrange(M):
        print random.randint(1,M), random.randint(1,M)
    Gs = []
    for i in xrange(M):
        Gs.append(str(random.randint(0,G)))
    print " ".join(Gs)
