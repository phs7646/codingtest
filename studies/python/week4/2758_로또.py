T = int(input())
for _ in range(T) :
    N,M = map(int,input().split())
    dp = [[0]*(M+1) for _ in range(N+1)] #dp[i][j] 는 j이상으로 i개 고르기
    for j in range(1,M+1) :
        dp[1][j] = M-j+1
    for i in range(2,N+1) :
        #dp[i][M] = 0
        for j in range(M-1,0,-1):
            dp[i][j] = dp[i][j+1]
            if 2 * j <= M :
                dp[i][j] += dp[i-1][2*j]
    print(dp[N][1])