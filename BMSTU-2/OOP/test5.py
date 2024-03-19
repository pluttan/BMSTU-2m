# 6
# 1
# 02:46:00-03:14:59
# 2
# 23:59:59-23:59:59
# 00:00:00-23:59:58
# 2
# 23:59:58-23:59:59
# 00:00:00-23:59:58
# 2
# 23:59:59-23:59:58
# 00:00:00-23:59:57
# 6
# 17:53:39-20:20:02
# 10:39:17-11:00:52
# 08:42:47-09:02:14
# 09:44:26-10:21:41
# 00:46:17-02:07:19
# 22:42:50-23:17:46
# 1
# 24:00:00-23:59:59
k = int(input())
for i in range(k):
    t = int(input())
    fl = True
    ls = []
    for j in range(t):
        st1, st2 = input().split("-")
        if (fl):
            stl1, stl2 = list(map(int, st1.split(":"))), list(
                map(int, st2.split(":")))
            if (stl1[0] > 23 or stl1[0] < 0 or stl2[0] > 23 or stl2[0] < 0 or
                stl1[1] > 59 or stl1[1] < 0 or stl2[1] > 59 or stl2[1] < 0 or
                    stl1[2] > 59 or stl1[2] < 0 or stl2[2] > 59 or stl2[2] < 0):
                print("NO")
                fl = False
            elif (stl1[0] > stl2[0]):
                print("NO")
                fl = False
            elif (stl1[0] == stl2[0] and stl1[1] > stl2[1]):
                print("NO")
                fl = False
            elif (stl1[0] == stl2[0] and stl1[1] == stl2[1] and stl1[2] > stl2[2]):
                print("NO")
                fl = False
            if (fl):
                p = [stl1[0]*3600+stl1[1]*60+stl1[2],
                     stl2[0]*3600+stl2[1]*60+stl2[2]]
                ls.append(p)
    if fl:
        for i1 in range(len(ls)):
            for i2 in range(i1+1, len(ls)):
                if (i1 != i2 and ((ls[i1][0] >= ls[i2][0] and ls[i1][0] <= ls[i2][1]) or
                                  (ls[i1][1] >= ls[i2][0] and ls[i1][1] <= ls[i2][1]) or
                                  (ls[i2][0] >= ls[i1][0] and ls[i2][0] <= ls[i1][1]) or
                                  (ls[i2][1] >= ls[i1][0] and ls[i2][1] <= ls[i1][1])) and fl):
                    print("NO")
                    fl = False
    if fl:
        print("YES")
