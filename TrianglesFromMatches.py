def solution(n):
    if n < 1:
        return 0
    hexagon = int((n / 6) ** (1 / 2))
    odd_number = 1 + ((hexagon - 1) * 2)
    hexm = hexagon * 2
    # print("odd_number", odd_number)
    # print("hexagon", hexagon)
    diagonal_1 = (odd_number + hexagon) * hexagon + hexm
    # print("diagonal_1", diagonal_1)
    diagonal_2 = (odd_number + hexagon) * hexagon + hexm
    hortizontal = (odd_number + hexagon) * hexagon + hexm
    matches = diagonal_1 + diagonal_2 + hortizontal
    # print("matches", matches)
    remainder = n - (hexagon ** 2 * 6)
    # print("remainder", remainder)
    short_side = 2 * hexagon
    has_sides = False
    # print("short_side", short_side)
    if remainder >= short_side:
        remainder -= short_side
        matches += 3 * hexagon + 1
        has_sides = True
        # print("check")
    side = int(remainder / (2 * hexagon + 1))
    # print("side", side)
    diagonal_1_s = (hexagon + 1) * side
    # print("diagonal_1_s", diagonal_1_s)
    diagonal_2_s = hexagon * side
    hortizontal_s = (hexagon + 1) * side
    matches += diagonal_1_s + diagonal_2_s + hortizontal_s
    remainder -= side * (odd_number + 2)
    # print("remainder", remainder)
    if remainder:
        if remainder % 2:
            matches += (3 * remainder + 1) // 2
        if not remainder % 2:
            matches += (3 * remainder) // 2
    return matches
    # matches += diagonal_1_s + diagonal_1_s + hortizontal_s

n = int(input())
print(solution(n))
