a = input()
b = input()

if len(a) > len(b):
    a, b = b, a

res = []
for i in range(len(b)):
    res.append([0, -1, -1])

for i in range(len(a)):
    Max = [res[0][0], res[0][1], res[0][2]]
    for j in range(len(b)):
        if (a[i] == b[j]) and (j > Max[1]) and (i > Max[2]) and (Max[0]+1 > res[j][0]):
            res[j][0] = Max[0]+1
            res[j][1] = j
            res[j][2] = i
            Max[0] = 0
        else:
            if res[j][0] > Max[0]:
                Max[0] = res[j][0]
                Max[1] = res[j][1]
                Max[2] = res[j][2]
# print(res)
t = 0
for i in range(len(res)):
    if res[i][0] > t:
        t = res[i][0]
print(t)