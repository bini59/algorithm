n = int(input())

nums = list(map(int, input().split()))
operatorNums = list(map(int, input().split()))

def calculate(operator):
    global nums
    t = nums[0]
    for i in range(0, len(operator)):
        if operator[i] == 1:
            t += nums[i+1]
        elif operator[i] == 2:
            t -= nums[i+1]
        elif operator[i] == 3:
            t *= nums[i+1]
        elif operator[i] == 4:
            if t < 0:
                t = -t
                t //= nums[i+1]
                t = -t
            else:
                t //= nums[i+1]  

    return t
            
    
Min = 1000000000
Max = -1000000000


# 중복 순열 함수
def permutation(n, arr):
    global Max, Min
    if n == len(arr)-1:
        res = calculate(arr)
        if res < Min:
            Min = res
        if res > Max:
            Max = res
        return
    permutation(n+1, arr)
    for i in range(n+1, len(arr)):
        if arr[n] != arr[i]:
            arr[n], arr[i] = arr[i], arr[n]
            permutation(n+1, arr)
            arr[n], arr[i] = arr[i], arr[n]

operator = []

for i in range(len(operatorNums)):
    for j in range(operatorNums[i]):
        operator.append(i+1)


permutation(0, operator)


print(Max)
print(Min)