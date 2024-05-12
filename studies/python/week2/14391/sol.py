N, M = map(int,input().split())
board = []
value = 0
answer = 0
for i in range(N) :
    l = input()
    board.append([int(c) for c in l])
    
max_bit = 1 << (N*M)
for bit in range(max_bit):
    #draw value from bit
    visited = [[False] * M for _ in range(N)]
    value = 0
    for target in range(N*M):
        i = target // M
        j = target % M
        if visited[i][j] :
            continue
        if bit & (1<<(i*M+j)) :
            tmp = 0
            for k in range(i,N):
                if bit & (1<<(k*M+j)) :
                    tmp = tmp * 10 + board[k][j]
                    visited[k][j] = True
                else :
                    break
            value += tmp
        else :
            tmp = 0
            for k in range(j,M):
                if not (bit & (1<<(i*M+k))) :
                    tmp = tmp * 10 + board[i][k]
                    visited[i][k] = True
                else :
                    break
            value += tmp
    
    if not all(all(row) for row in visited) :
        print(2/0)
    answer = max(answer,value)
print(answer)