import sys
sys.setrecursionlimit(20000)
moves = [[0,1],[1,0],[-1,0],[0,-1]]

def dfs(board,y,x):
    H,W = len(board),len(board[0])
    board[y][x] = '.'
    for move in moves:
        newy = y + move[0]
        newx = x + move[1]
        if 0 <= newy < H and 0 <= newx < W and board[newy][newx] == '#':
            dfs(board,newy,newx)


T = int(input())
for _ in range(T) :
    H,W = map(int,input().split())
    board = [list(input()) for _ in range(H)]
    answer = 0
    for i in range(H) :
        for j in range(W) :
            if board[i][j] == '#' :
                answer+=1
                dfs(board,i,j)
    print(answer)
    