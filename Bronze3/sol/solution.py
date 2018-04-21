n = int(input())
x = 0
y = 0
while n != 0:
    r = n % 4
    if r == 0:
        x += 1
    elif r == 1:
        y += 1
    elif r == 2:
        x -= 1
    else: # r == 3
        y -= 1
    n = int(n/4)
print("{}, {}".format(x, y))
