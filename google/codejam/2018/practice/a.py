import sys

def solve():
    a, b = map(int, raw_input().strip().split())
    a += 1
    n = int(input())
    mid = (a + b) / 2
    while n > 0:
        print(mid)
        sys.stdout.flush()
        resp = raw_input()
        if resp == 'CORRECT':
            break
        elif resp == 'TOO_SMALL':
            a = mid + 1
        elif resp == 'TOO_BIG':
            b = mid - 1
        mid = (a + b) / 2
   
for case in xrange(input()):
    solve()
    