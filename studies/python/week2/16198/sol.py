
N = int(input())
W = list(map(int,input().split()))

max_bit = 1 << N
memo = [-1] * max_bit


def recur(bit) :
    global memo
    if memo[bit] >= 0 :
        return memo[bit]
    alive = []
    for i in range(N):
        if bit & (1<<i) :
            alive.append(i)
    if len(alive) <= 2:
        memo[bit] = 0
        return 0
    maximum = 0
    for i in range(1,len(alive)-1):
        new_bit = bit ^ (1<<alive[i])
        maximum = max(maximum,recur(new_bit) + W[alive[i-1]] * W[alive[i+1]])
    memo[bit] = maximum
    return memo[bit]
        

print(recur(max_bit-1))
