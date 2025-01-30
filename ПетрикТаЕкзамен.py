from math import floor
a, b, x, y = map(int, input().split())
solved_easy = a - x
soled_hard = b - y
solved = solved_easy * 1 + soled_hard * 2
percentage = floor(solved/(a * 1 + b * 2) * 100)
if percentage >= 51:
    print("YES")
else:
    print("NO")
