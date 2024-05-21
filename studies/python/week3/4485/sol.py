import heapq

count = 1
while True :
    N = int(input())
    if(N == 0) :
        break
    board = [list(map(int,input().split())) for _ in range(N)]
    dist = [[9*125*125] * N for _ in range(N)]
    visited = [[False] * N for _ in range(N)]
    hq = []
    dist[0][0] = board[0][0]    
    num_visit = 0
    heapq.heappush(hq, (dist,0,0))
    moves = [[1,0],[-1,0],[0,1],[0,-1]]
    while num_visit < N*N :
        d,y,x = heapq.heappop(hq)
        while visited[y][x] == True:
            d,y,x = heapq.heappop(hq)
        visited[y][x] = True
        num_visit+=1
        for move in moves:
            newy = y + move[0]
            newx = x + move[1]
            if 0 > newy or newy >= N or 0 > newx or newx >= N :
                continue
            newcost = dist[y][x] + board[newy][newx]
            if newcost < dist[newy][newx] :
                dist[newy][newx] = newcost
                heapq.heappush(hq,(newcost,newy,newx))
    print("Problem {}: {}".format(count,dist[N-1][N-1]))
    count+=1
    
