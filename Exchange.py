def order(k):
    V = 2
    G = 0
    C = 1
    for i in range(k):
        V = (V + 1) % 3
        G = (G + 1) % 3
        C = (C + 1) % 3
    result = [0] * 3
    result[V] = "V"
    result[G] = "G"
    result[C] = "C"
    stringa = result[0] + result[1] + result[2]
    return stringa




t = int(input())
k_list = []
for i in range(t):
    k_list.append(int(input()))
for i in k_list:
    print(order(i))
