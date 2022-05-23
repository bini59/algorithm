import sys
input = sys.stdin.readline
n = int(input())

avg = 0
li = [0 for _ in range(n)]
for i in range(n):
    a = int(input())
    li[i] = a; avg += a

li.sort()

print(round(avg/n))

print(li[n//2])

max = -4001; min = 4001

many = [[4001, 0]]

for i in range(n):
    if li[i] > max:
        max = li[i]
    if li[i] < min:
        min = li[i]
    if li[i] == many[-1][0]:
        many[-1][1] += 1
    else:
        many.append([li[i], 1])

many.sort(key=lambda x: (-x[1], x[0]))
if many[0][1] != many[1][1]:
    print(many[0][0])
else:
    print(many[1][0])
print(max-min)

