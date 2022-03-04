# void combination(vector<int> numbers, int k, int n){
#     vector<int> temp(n);
#     for(int i = k; i < n+k-1; i++)
#         temp[i-k] = numbers[i];
    
#     for(int i = n+k-1; i < (int)numbers.size(); i++){
#         temp[n-1] = numbers[i];
#     }

# }


# def combination(nums, k, n):
#     temp = list(range(0, n))
#     for i in range(k, n+k-1):
#         temp[i-k] = nums[i]

#     for i in range(n+k-1, len(nums)):
#         temp[n-1] = nums[i]

#     return temp


# def combi(nums, n):
#     temp = list(range(0, n))

#     res = [0] * n

#     while True:
#         for i in range(n):
#             for j in range(temp[i], len(nums)-n+i+1):
#                 res[i] = nums[j]
#                 print(res)

temp = [0] * 4
def combination(li, k, n, z):
    global temp
    for i in range(k+z, len(li)-n+k+1):
        temp[k] = li[i]
        if k == n-1:
            print(temp)
        else:
            combination(li, k+1, n, z+i-k-z)
            
            
t = [1, 2, 3, 4, 5, 6]
combination(t, 0, 4, 0)