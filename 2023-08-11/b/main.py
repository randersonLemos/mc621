x1, y1, x2, y2 = input().split(' ')
x1 = int(x1); y1 = int(y1); x2 = int(x2); y2 = int(y2)

day = 0

if x1 > x2:
    print(day)

elif y1 <= y2:
    print(-1)

else:
    x = x2 - x1
    y = y1 - y2
    d = int(x/y) + 1
    print(d)


