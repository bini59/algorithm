a = int(input())

for i in range(a):
    n = int(input())
    t = list(input())
    res = 0
    for j in range(n):
        temp = True
        for k in range(n):
            t1 = k
            t2 = n-k-1
            if(t2 < j):
                t1 -= 1
            if(t1 > j):
                t2 += 1
            if(t1 == j or t2 == j):
                continue
            if(t[t1] != t[t2]):
                # print(f"{k} {j} {t[t1]} {t[t2]} {t1} {t2}F ")
                temp = False
                break
        if(temp):
            res += 1
    #         print(f"{j} True", end=" ")
    # print()
    
    print(res)