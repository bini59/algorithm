Mod = 11

n, k = map(int, input().split())

facto = [1] * (n)

for i in range(1, n):
    facto[i] = facto[i-1]*(i+1)

print(facto[2000])
    
print((facto[n-1]//(facto[k-1]*facto[n-k-1]))%Mod)
