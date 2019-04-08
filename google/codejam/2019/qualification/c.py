import math

letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

def solve():
    n, l = map(int, input().split())
    vals = list(map(int, input().split()))

    for i in vals:
        if i != vals[0]:
            break

    p2 = gcd(vals[0], i)
    p1 = vals[0] // p2

    primes = []
    can = True
    primes.append(p1)
    for i in vals:
        if (i % p1) or p1 == 0:
            can = False
            break
        p1 = i // p1
        primes.append(p1)
    
    if not can:
        primes = []
        primes.append(p2)
        for i in vals:
            p2 = i // p2
            primes.append(p2)

    s_primes = sorted(list(set(primes)))

    v_map = {}
    for i in range(len(s_primes)):
        v_map[s_primes[i]] = letters[i]

    s = ""
    for i in primes:
        s += v_map[i]
    
    return s

t = int(input())
for i in range(1, t + 1):
    print("Case #" + str(i) + ": " + solve())