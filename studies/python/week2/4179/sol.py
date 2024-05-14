import queue

R, C = map(int,input().split())

board = [[0]*C for _ in range(R)]
moves = [[-1,0], [1,0] , [0,-1], [0,1]]

start = (0,0)
fires = queue.Queue()
for i in range(R) :
    line = input().strip()
    for j in range(C) :
        if(line[j] == '#') :
            board[i][j] = -1
        elif(line[j] == 'F') :
            board[i][j] = 1
            fires.put((i,j))
        elif(line[j] == 'J') :
            start = (i,j)

if start[0] == 0 or start[0] == R-1 or start[1] == 0 or start[1] == C-1 :
    print(1)
    exit(0)

#bfs fire
while not fires.empty() :
    y,x = fires.get()
    value = board[y][x]
    for move in moves :
        newy = y + move[0]
        newx = x + move[1]
        if newy < 0 or newy >= R :
            continue
        if newx < 0 or newx >= C :
            continue
        if board[newy][newx] != 0 :
            continue
        board[newy][newx] = value+1
        fires.put((newy,newx))


#bfs start
players = queue.Queue()
players.put([start[0],start[1],1])
board[start[0]][start[1]] = -1

while not players.empty() :
    y,x,day = players.get() #day+2 이상인 칸에 방문가능
    for move in moves:
        newy = y + move[0]
        newx = x + move[1]
        if newy < 0 or newy >= R :
            continue
        if newx < 0 or newx >= C :
            continue
        if board[newy][newx] != 0 and board[newy][newx] <= day+1 :
            continue
        
        if newx == 0 or newx == C-1 or newy == 0 or newy == R-1 :
            #탈출
            print(day+1)
            exit(0)
        board[newy][newx] = -1
        players.put([newy,newx,day+1])

print("IMPOSSIBLE")