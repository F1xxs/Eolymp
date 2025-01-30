def f(v, day_count):
    amount = v[1]
    day = v[0]
    return amount * (day - day_count)


def s(vouchers, day_count, total):
    maximum = 0
    for i, v in enumerate(vouchers):
        if v[0] - day_count > 0: 
            maximum = max(maximum, s(vouchers[:i] + vouchers[i+1:], day_count + 1, f(v, day_count)))
    return total + maximum


n = int(input())
vouchers = []
for i in range(0, n):
    a, b = map(int, input().split())
    vouchers.append((a, b))
print(s(vouchers, 0, 0))
