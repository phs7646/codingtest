def recur(player, v, occup):
    if player >= 11:
        if not all(occup):
            return -1 # 불가능
        return 0 # 완성
    
    maximum = -1
    for i in range(11):
        if not occup[i] and v[player][i] != 0:
            occup[i] = True
            value = recur(player + 1, v, occup)
            if value != -1:
                maximum = max(maximum, value + v[player][i])
            occup[i] = False
    return maximum

T = int(input())

for _ in range(T):
    v = []
    for i in range(11):
        v.append(list(map(int,input().split())))
    occup = [False] * 11
    result = recur(0, v, occup)
    print(result)

