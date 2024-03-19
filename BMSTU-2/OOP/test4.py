# 5
# 2 1 3 1 2 3 1 1 4 2
# 1 1 1 2 2 2 3 3 3 4
# 1 1 1 1 2 2 2 3 3 4
# 4 3 3 2 2 2 1 1 1 1
# 4 4 4 4 4 4 4 4 4 4
k = int(input())
for i in range(k):
    p = list(map(int, input().split()))
    if (p.count(1) == 4 and p.count(2) == 3 and p.count(3) == 2 and p.count(4) == 1):
        print("YES")
    else:
        print("NO")
