n = list(input())
a = 0
for i in range(len(n)):
    a += int(n[i])
if(a%3 == 0):
    n.sort()
    if(n[0] != "0"):
        print(-1)
    else:
        print("".join(n[::-1]))
else:
    print(-1)



