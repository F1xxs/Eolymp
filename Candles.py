from math import comb
n, s = map(int, input().split())    

a = comb(n + s - 1, s - 1)
b = ((n//2) + s - 1) * comb((n//2) + s - 2, s-1)
c = (n//2 + s - 2)* comb(n//2 + s - 3, s-1)
print(a - b + c)
