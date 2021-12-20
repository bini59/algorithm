n, m = map(int, input().split())

t = 0

if n-m > m:
    t = m
else:
    t = n-m

up = list(range(n-t+1, n+1))
down = list(range(1, t+1))


for i in range(len(down)):
    for j in range(len(up)):
        if up[j] % down[i] == 0:
            up[j] //= down[i]
            down[i] = 1
            break

result = 1
for i in range(len(up)):
    result *= up[i]

tt = 1
for i in range(len(down)):
    tt *= down[i]

print(result//tt)