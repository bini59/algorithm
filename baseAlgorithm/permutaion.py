def permutation(n, arr):
    if n == len(arr)-1:
        print(arr)
        return

    for i in range(n, len(arr)):
        arr[n], arr[i] = arr[i], arr[n]
        permutation(n+1, arr)
        arr[n], arr[i] = arr[i], arr[n]


t = [1, 2, 3, 4]

permutation(0, t)