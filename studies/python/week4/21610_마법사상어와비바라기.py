N,M = map(int,input().split())
board = [list(map(int,input().split())) for _ in range(N)]
moves = [(0,0),(0,-1),(-1,-1),(-1,0),(-1,1),(0,1),(1,1),(1,0),(1,-1)]
query = [list(map(int,input().split())) for _ in range(M)]
close = [(-1,-1),(-1,1),(1,-1),(1,1)]

cloud = [[0]*N for _ in range(N)]
cloud[N-1][0] = 1
cloud[N-1][1] = 1
cloud[N-2][0] = 1
cloud[N-2][1] = 1

def move_cloud(cloud,dir,amount):
    new_cloud = [[0]*N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            if cloud[i][j] == 1 :
                new_i = (i + moves[dir][0] * amount) % N
                new_j = (j + moves[dir][1] * amount) % N
                new_cloud[new_i][new_j] = 1
    return new_cloud

def copy_bug(board,cloud) :
    for i in range(N) :
        for j in range(N) :
            if cloud[i][j] == 1 :
                for c in close :
                    new_i = i + c[0]
                    new_j = j + c[1]
                    if 0 <= new_i < N and 0 <= new_j < N and board[new_i][new_j] > 0:
                        board[i][j] += 1
    return board
            

for t in range(M):
    #moce cloud
    cloud = move_cloud(cloud,query[t][0],query[t][1])
    
    #rain
    for i in range(N) :
        for j in range(N) :
            board[i][j] += cloud[i][j]
            
    #copy bug
    board = copy_bug(board,cloud)
    
    #create cloud
    new_cloud = [[0]*N for _ in range(N)]
    for i in range(N) :
        for j in range(N) :
            if board[i][j] >= 2 and cloud[i][j] == 0:
                new_cloud[i][j] = 1
                board[i][j] -= 2
    cloud = new_cloud
    

s = 0
for i in range(N) :
    for j in range(N) :
        s += board[i][j]
        
print(s)