import sys
import random
import string

N = int(sys.argv[1])
ratio_identical = float(sys.argv[2])

assert 1 <= N <= 100000
assert 0 <= ratio_identical <= 1

s = list("".join(random.choices(string.ascii_uppercase, k=N)).lower())

for i in range(int(N/2)):
    c = N-i-1
    if random.random() <= ratio_identical:
        s[c] = s[i]
print("".join(s))
