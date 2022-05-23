a = int(input())

li = list(map(int, input().split()))

result = [0 for _ in range(a)]

temp = [li[-1], a-1]
for i in range(a-1, 0, -1):
    if temp[0] < li[i]:
        for j in range(temp[1], i, -1):
            result[j] = i+1
        temp[0] = li[i]
        temp[1] = i
    
print(result)