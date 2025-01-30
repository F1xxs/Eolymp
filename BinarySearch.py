def binary_search(list_1, x):
    b = 0
    t = len(list_1) - 1
    while b <= t:
        middle = (b + t) // 2
        if list_1[middle] == x:
            return "YES"
        if list_1[middle] < x:
            b = middle + 1
        else:
            t = middle - 1
    return "NO"


n, q = map(int, input().split())
list_1 = list(map(int, input().split()))
for i in range(q):
    print(binary_search(list_1, int(input())))
