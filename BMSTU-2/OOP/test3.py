a, b = map(int, input().split())
if a < b:
    a, b = b, a
if (abs(a)-abs(b) < 2):
    print(0 if a % 3 != 2 else 1)
else:
    while (a % 3 != 2):
        a -= 1
    if a > 0 and b > 0:
        k = a-b
        print(abs(k//3+1))
    elif a > 0 and b < 0:
        b = abs(b)
        while (b % 3 != 2):
            b -= 1
        print(abs(a//3+1)+abs(b//3+1))
    else:
        k = abs(a-b)
        print(abs(k//3+1))
