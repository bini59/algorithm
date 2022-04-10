import sys
import copy

sys.setrecursionlimit(20000)

def move(plane, type, K):
    res = 0
    n = len(plane)

    if type == 0:
        for i in range(n):
            for j in range(n-1, 0, -1):
                for k in range(j-1, -1, -1):
                    if plane[i][k] == 0:
                        continue
                    elif plane[i][k] == plane[i][j]:
                        plane[i][j] *= 2
                        plane[i][k] = 0
                        break
                    elif plane[i][j] == 0:
                        plane[i][j] = plane[i][k]
                        plane[i][k] = 0
                    else:
                        temp = plane[i][k]
                        plane[i][k] = 0
                        plane[i][j-1] = temp
                        break
                res = max(res, plane[i][j])
    if type == 1:
        for i in range(n):
            for j in range(0, n-1):
                for k in range(j+1, n):
                    if plane[i][k] == 0:
                        continue
                    elif plane[i][k] == plane[i][j]:
                        plane[i][j] *= 2
                        plane[i][k] = 0
                        break
                    elif plane[i][j] == 0:
                        plane[i][j] = plane[i][k]
                        plane[i][k] = 0
                    else:
                        temp = plane[i][k]
                        plane[i][k] = 0
                        plane[i][j+1] = temp
                        break
                res = max(res, plane[i][j])
    if type == 2:
        for j in range(n):
            for i in range(n-1, 0, -1):
                for k in range(i-1, -1, -1):
                    if plane[k][j] == 0:
                        continue
                    elif plane[k][j] == plane[i][j]:
                        plane[i][j] *= 2
                        plane[k][j] = 0
                        break
                    elif plane[i][j] == 0:
                        plane[i][j] = plane[k][j]
                        plane[k][j] = 0
                    else:
                        temp = plane[k][j]
                        plane[k][j] = 0
                        plane[i-1][j] = temp
                        break
                res = max(res, plane[i][j])
    if type == 3:
        for j in range(n):
            for i in range(0, n-1):
                for k in range(i+1, n):
                    if plane[k][j] == 0:
                        continue
                    elif plane[k][j] == plane[i][j]:
                        plane[i][j] *= 2
                        plane[k][j] = 0
                        break
                    elif plane[i][j] == 0:
                        plane[i][j] = plane[k][j]
                        plane[k][j] = 0
                    else:
                        temp = plane[k][j]
                        plane[k][j] = 0
                        plane[i+1][j] = temp
                        break
                res = max(res, plane[i][j])

    # if (K == 0):
    #     for i in range(n):
    #         print(plane[i])
    #     print("\n\n")
    if K==4:
        # print(f"return {res}")
        return res


    for i in range(4):
        res = max(res, move(copy.deepcopy(plane), i, K+1))
    
    return res

n = int(input())
li = [[] for _ in range(n)]
for i in range(n):
    li[i] = list(map(int, input().split()))


# print(li)
result = 0

for i in range(4):
    t = move(copy.deepcopy(li), i, 0)
    # print(f"실행 {i}번째")
    result = max(result, t)

if n == 1:
    result = li[0][0]

print(result)