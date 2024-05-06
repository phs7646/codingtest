

T = int(input())
for _ in range(T) :
    N = int(input())
    v1 = list(map(int,input().split()))
    v2 = list(map(int,input().split()))
    dp = [[0,0,0] for _ in range(N)] #dp[i][0] : 둘다 안골랐을 때 최댓값, [1] : 위에꺼 골랐을 때 최댓값, [2] : 아랫꺼 골랐을 때 최댓값
    dp[0][1] = v1[0]
    dp[0][2] = v2[0]
    
    for i in range(1,N) :
        dp[i][0] = max(dp[i-1][0],dp[i-1][1],dp[i-1][2])
        dp[i][1] = max(dp[i-1][0],dp[i-1][2]) + v1[i]
        dp[i][2] = max(dp[i-1][0],dp[i-1][1]) + v2[i]
    #print(dp)
    print(max(dp[N-1][0],dp[N-1][1],dp[N-1][2]))