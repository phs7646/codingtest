N,M = map(int,input().split())
arr = list(set(map(int,input().split())))
arr = sorted(arr)
N = len(arr)

#maximum is N^M
max = N**M

for bit in range(max) :
    list = []
    cur = bit
    for i in range(M) :
        list.append(arr[cur % N])
        cur //= N
    print(" ".join(map(str,list[::-1])))