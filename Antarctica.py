n = int(input())
list1 = []
for i in range(0, n):
    a, b = map(int, input().split())
    list1.append((a, b))
directions = [(0, 1), (1, 0), (-1, 0), (0, -1), (-1, 1), (1, -1), (-1, -1), (1, 1)]
s = set(list1)
groups = []
count = 0
while s:
    group = [s.pop()]
    i, h = 0, 1
    while i < h:
        for d in directions:
            p = (group[i][0] + d[0], group[i][1] + d[1])
            if p in s:
                group.append(p)
                s.remove(p)
                h += 1
        i += 1
    count += 1
print(count)
