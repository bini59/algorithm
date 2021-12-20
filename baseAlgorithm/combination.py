# void combination(vector<int> numbers, int k, int n){
#     vector<int> temp(n);
#     for(int i = k; i < n+k-1; i++)
#         temp[i-k] = numbers[i];
    
#     for(int i = n+k-1; i < (int)numbers.size(); i++){
#         temp[n-1] = numbers[i];
#     }

# }


def combination(nums, k, n):
    temp = list(range(0, n))
    for i in range(k, n+k-1):
        temp[i-k] = nums[i]

    for i in range(n+k-1, len(nums)):
        temp[n-1] = nums[i]