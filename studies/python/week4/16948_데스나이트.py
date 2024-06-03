from collections import deque

moves =  [(-2, -1), (-2, +1), (0, -2), (0, +2), (+2, -1), (+2, +1)]

N = int(input())
board = [[-1]*N for _ in range(N)]
r1,c1,r2,c2 = map(int,input().split())

board[r1][c1] = 0
q = deque()
q.append((r1,c1))

while len(q) > 0 :
    r,c = q.popleft()
    cur = board[r][c]
    for move in moves:
        newr = r + move[0]
        newc = c + move[1]
        if 0 <= newr < N and 0 <= newc < N and board[newr][newc] == -1 :
            if newr == r2 and newc == c2 :
                print(cur+1)
                exit()
            board[newr][newc] = cur+1
            q.append((newr,newc))
print(-1)

