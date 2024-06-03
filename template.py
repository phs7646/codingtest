import sys

N,Q = map(int,sys.stdin.readline().rstrip().split())
coms = [False] * N
num = N
for _ in range(Q) :
    query = list(map(int,sys.stdin.readline().rstrip().split()))
    if len(query) == 1 :
        print(num)
    elif query[0] == 1 :
        if coms[query[1]-1] == False :
            num-=1
        coms[query[1]-1] = True
    elif query[0] == 2 :
        if coms[query[1]-1] == True:
            num+=1
        coms[query[1]-1] = False