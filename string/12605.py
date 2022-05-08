n = int(input())
for i in range(n):
    s = input().split()
    print(f"Case #{i+1}:", end=" ")
    for j in range(len(s)-1, -1, -1):
        print(f"{s[j]}", end=" ")