def alphaToint(al):
    return ord(al)-97

n, k = map(int, input().split())

li = ["" for _ in range(n)]

alpha = [0 for _ in range(26)]

alpha[alphaToint('a')] = alpha[alphaToint('c')] = alpha[alphaToint('i')] = alpha[alphaToint('n')] = alpha[alphaToint('t')] = 1
k -= 5

for i in range(n):
    li[i] = input()[4:-4]


def countWord(alpha):
    global li
    # print(alpha)
    res = 0
    for i in li:
        temp = True
        for j in i:
            if alpha[alphaToint(j)] == 0:
                temp = False
        if temp:
            res += 1
    return res
    

# k 는 시작위치
# n 은 총 바꿀 개수
# l 은 현재 몇번째
def sol(alpha, k, n, l):
    res = 0
    if n == l:
        return countWord(alpha) 
    for i in range(k, 26-(n-l-1)):
        if alpha[i] == 1:
            continue
        else:
            alpha[i] = 1
            res = max(res, sol(alpha, i+1, n, l+1))
            alpha[i] = 0

    return res



# print(alpha)
# print(li)
if k < 0:
    result = 0
else:
    result = sol(alpha, 0, k, 0)


print(result)