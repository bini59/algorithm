import sys

n = int(input())

fibo = [0, 1]
i = 2


for i in range(n):
    fibo = [0, 1]
    i = 2
    t = int(sys.stdin.readline())
    res = []
    while(fibo[i-1] < t):
        fibo.append(fibo[i-1] + fibo[i-2])
        i += 1
    while(t != 0):
        if(t >= fibo[i-1]):
            t -= fibo[i-1]
            res.append(fibo[i-1])
        i -= 1
    for i in range(len(res)):
        print(f"{res[len(res)-i-1]}", end=" ")
