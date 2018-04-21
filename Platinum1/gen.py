from random import *
import sys

N = int(sys.argv[1])
Q = int(sys.argv[2])
upd_ratio = float(sys.argv[3])

assert N <= 10000
assert Q <= 10000
assert 0 <= upd_ratio <= 1
PRIME_RATIO = .25

t1 = [0]*1002

for i in range(2, 1000):
    if t1[i] == 1: continue
    j = i*2
    while j < 1000:
        t1[j] = 1
        j += i

primes = []
for i in range(2, 1000):
    if t1[i] == 0:
        primes.append(i)

a = []
for i in range(N):
    if random() <= PRIME_RATIO:
        a.append(choice(primes))
    else:
        a.append(randint(1, 1000))

print(N)
print(" ".join(list(map(str, a))))
print(Q)

for i in range(Q):
    v = 0
    if random() <= PRIME_RATIO:
        v = choice(primes)
    else:
        v = randint(1, 1000)
    if random() <= upd_ratio:
        print("C {} {}".format(randint(0, N-1), v))
    else:
        i = randint(0, N-1)
        print("F {} {} {}".format(i, randint(i, N-1), v))



    
