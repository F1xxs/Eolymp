n = int(input())
square = int(n**(1/2))
# print("square", square)
horizontal = square * (square + 1)
vertical = square * (square + 1)
matches = horizontal + vertical
# print("matches", matches)
remainder = n - (square**2)
# print("remainder", remainder)
side = remainder // square
matches += (side * square) + side * (square + 1)
remainder -= side * square
if remainder < side:
    matches += remainder * 2
else:
    if remainder > 0:
        matches += 3 + (remainder-1) * 2
print(matches)
