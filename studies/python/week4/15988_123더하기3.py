mod =  1000000009

T = int(input())
inputs = [int(input()) for _ in range(T)]
max_input = max(inputs)

dp = [0] * (max_input+1)
dp[0] = 0
dp[1] = 1
dp[2] = 2
dp[3] = 4
for i in range(4,max_input+1) :
    dp[i] = (((dp[i-3] + dp[i-2]) % mod) + dp[i-1])%mod
    
for i in inputs:
    print(dp[i])