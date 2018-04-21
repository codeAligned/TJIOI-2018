from random import *
import math
import sys

N = int(sys.argv[1])
Q = int(sys.argv[2])

# N <= 2*10^5, Q <= 2*10^5
assert N <= 200000
assert Q <= 200000

ans = randint(1, Q)
K = 0
for i in range(1, ans+1):
    K += ans // i

print(N, K)
l = []
for i in range(N):
    l.append(randint(1, Q))
shuffle(l)
for i in l:
    print(i)
