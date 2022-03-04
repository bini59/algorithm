# void combination(vector<int> numbers, int k, int n){
#     vector<int> temp(n);
#     for(int i = k; i < n+k-1; i++)
#         temp[i-k] = numbers[i];
    
#     for(int i = n+k-1; i < (int)numbers.size(); i++){
#         temp[n-1] = numbers[i];
#     }

# }

a, b = map(int, input().split())


def check(li):
    tmp = ["a", "e", "i", "o", "u"]
    gat = 0
    for i in li:
        if i in tmp:
            gat += 1
    if len(li) - gat >=2 and gat > 0:
        return True
    else:
        return False


# k = 0, z = 0 고정
# n => 원하는 개수
n = a
temp = [0] * n
def combination(li, k, n, z):
    global temp
    for i in range(k+z, len(li)-n+k+1):
        temp[k] = li[i]
        if k == n-1:
            if check(temp):
                print(''.join(temp))
            else:
                continue
        else:
            combination(li, k+1, n, z+i-k-z)


            




chars = list(input().split())
chars.sort()



combination(chars, 0, n, 0)