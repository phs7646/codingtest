import queue

M,N,K = map(int,input().split())

board = [[0] * N for _ in range(M)]

for _ in range(K):
    ax,ay,bx,by = map(int,input().split())
    for x in range(ax,bx):
        for y in range(ay,by):
            board[y][x] = 1


moves = [[1,0],[-1,0],[0,1],[0,-1]]
def bfs(y,x):
    global board
    board[y][x] = 1
    ret = 1
    q = queue.Queue()
    q.put((y,x))
    while(not q.empty()):
        y,x = q.get()
        for move in moves:
            newy = y + move[0]
            newx = x + move[1]
            if(newy >= 0 and newy < M and newx >= 0 and newx < N and board[newy][newx] == 0):
                board[newy][newx] = 1
                q.put((newy,newx))
                ret+=1
    return ret
        
            

areas = []
for y in range(M):
    for x in range(N):
        if(board[y][x] == 0) :
            areas.append(bfs(y,x))

print(len(areas))
print(" ".join(map(str,sorted(areas))))
    