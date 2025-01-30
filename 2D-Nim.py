def makepoints(list1):
    group = set(zip(list1[0::2], list1[1::2]))
    # group = []
    # x = 0
    # y = 0
    # for i, g in enumerate(list1):
    #     if not i % 2:
    #         x = g
    #     elif i % 2:
    #         y = g
    #         group.append((x, y))
    return group


def directions(list1):
    directions = [(1, 0), (0, 1), (-1, 0), (0, -1)]
    s = list1
    groups = []
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
        groups.append(slide(group))
    return groups


def slide(group):
    group = list(group)
    min_x = float("inf")
    min_y = float("inf")
    for i in group:
        min_x = min(min_x, i[0])
        min_y = min(min_y, i[1])
    list1 = []
    for h in group:
        list1.append((h[0] - min_x, h[1] - min_y))
    list1.sort()
    return list1


def flip(group):
    return [[(x, y) for x, y in group], [(y, x) for x, y in group],
            [(-y, x) for x, y in group], [(-x, y) for x, y in group],
            [(-x, -y) for x, y in group], [(-y, -x) for x, y in group],
            [(x, -y) for x, y in group], [(y, -x) for x, y in group]
            ]


def comparison(group1, group2):
    group_d = {}
    for i in group1:
        if tuple(i) in group_d:
            group_d[tuple(i)] += 1
        else:
            group_d[tuple(i)] = 1
    for h in group2:
        # print("h", h)
        found = False
        for m in flip(h):
            m = slide(m)
            if tuple(m) in group_d and group_d[tuple(m)] > 0:
                group_d[tuple(m)] -= 1
                found = True
                break
        if not found:
            return False
    return True


n = int(input())
for k in range(n):
    _ = input()
    board1 = list(map(int, input().split()))
    board2 = list(map(int, input().split()))
    # print(board1)
    # print(board2)
    # print(makepoints(board1))
    board1 = makepoints(board1)
    board2 = makepoints(board2)
    # print(board1)
    # print(board2)
    board1 = directions(board1)
    board2 = directions(board2)
    m = comparison(board1, board2)
    if m:
        print("YES")
    else:
        print("NO")
