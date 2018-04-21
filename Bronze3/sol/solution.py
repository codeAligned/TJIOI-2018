n = int(raw_input())
x = 0
y = 0
while n != 0:
    r = n % 4
    if r == 0:
        y += 1
    elif r == 1:
        x += 1
    elif r == 2:
        y -= 1
    else: # r == 3
        x -= 1
    n = int(n/4)
print(str(x)+", "+str(y))
