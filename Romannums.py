def romanToInt(s):
    a = 0
    s_list = [*s, 4, 4]
    m_list = []
    for i, g in enumerate(s_list):
        if g == "I":
            if s_list[i + 1] == "V":
                a += 4
            elif s_list[i + 1] == "X":
                a += 9
            else:
                a += 1
        elif g == "V":
            if s_list[i - 1] == "I":
                a += 0
            else:
                a += 5
        elif g == "X":
            if s_list[i - 1] == "I":
                a += 0
            elif s_list[i + 1] == "L":
                a += 40
            elif s_list[i + 1] == "C":
                a += 90
            else:
                a += 10
        elif g == "L":
            if s_list[i - 1] == "X":
                a += 0
            else:
                a += 50
        elif g == "C":
            if s_list[i - 1] == "X":
                a += 0
            elif s_list[i + 1] == "D":
                a += 400
            elif s_list[i + 1] == "M":
                a += 900
            else:
                a += 100
        elif g == "D":
            if s_list[i - 1] == "C":
                a += 0
            else:
                a += 500
        elif g == "M":
            if s_list[i - 1] == "C":
                a += 0
            else:
                a += 1000
    # print(a)
    return a

def int_to_roman(input):
    ints = (1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1)
    nums = ("M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I")
    result = ""
    for i in range(len(ints)):
        count = int(input / ints[i])
        result += nums[i] * count
        input -= ints[i] * count
    return result

n = str(input())
print(int_to_roman(romanToInt(n)))
