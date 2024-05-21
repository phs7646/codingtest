N,M,R = map(int,input().split())

arr = [list(map(int,input().split())) for _ in range(N)]
arr2 = [[0] * M for _ in range(N)]

def newpos(i, j, num, padding):
    if num == 0:
        return i, j
    if i == padding and j > padding:
        dist = min(num, j - padding)
        num -= dist
        j -= dist
    if num == 0:
        return i, j
    if j == padding and i < N - padding - 1:
        dist = min(num, N - padding - i - 1)
        num -= dist
        i += dist
    if num == 0:
        return i, j
    if i == N - padding - 1 and j < M - padding - 1:
        dist = min(num, M - padding - j - 1)
        num -= dist
        j += dist
    if num == 0:
        return i, j
    if j == M - padding - 1 and i > padding:
        dist = min(num, i - padding)
        num -= dist
        i -= dist
    return newpos(i, j, num, padding)
        
for i in range(N) :
    for j in range(M) :
        padding = min(i,N-i-1,j,M-j-1)
        num = R % (2 * (N-2*padding-1) + 2 * (M-2*padding-1))
        y,x = newpos(i,j,num,padding)
        arr2[y][x] = arr[i][j]
        
for line in arr2 :
    print(" ".join(map(str,line)))