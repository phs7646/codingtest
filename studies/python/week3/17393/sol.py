import bisect

N = int(input())
A = list(map(int,input().split()))
B = list(map(lambda x : -1*x,list(map(int,input().split()))))[::-1]

answer = []
for i in range(N) :
    index = bisect.bisect_left(B,-1 * A[i])
    value = N-index-i-1
    if value > 0 :
        answer.append(value)
    else :
        answer.append(0)

print(" ".join(map(str,answer)))