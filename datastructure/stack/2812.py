n, m = map(int, input().split())

a = input()

stack = []
i = 0
while(m > 0 and i < len(a)):
    while(len(stack) != 0 and stack[-1] < a[i] and m > 0):
        stack.pop(-1)
        m -= 1 
    stack.append(a[i])
    i += 1

for k in range(m):
    stack.pop(-1)
for j in range(i, len(a)):
    stack.append(a[j])

print(''.join(stack))
