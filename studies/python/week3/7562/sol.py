from collections import deque

T = int(input())

moves = [(-2,+1),(-1,+2),(+1,+2),(+2,+1),(+2,-1),(+1,-2),(-1,-2),(-2,-1)]
for _ in range(T) :
    N = int(input())
    sy, sx = map(int,input().split())
    ey, ex = map(int,input().split())
    board = [[-1]*N for _ in range(N)]
    board[sy][sx] = 0
    q = deque()
    q.append((sy,sx))
    while len(q) > 0:
        y,x = q.popleft()
        cur = board[y][x]
        for move in moves:
            ny = y + move[0]
            nx = x + move[1]
            if 0 <= nx < N and 0 <= ny < N and board[ny][nx] == -1:
                board[ny][nx] = cur+1
                q.append((ny,nx))
        if board[ey][ex] != -1:
            break
    print(board[ey][ex])