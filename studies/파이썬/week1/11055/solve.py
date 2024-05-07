
N = int(input())
v = list(map(int, input().split()))

# DP[i] 는 i번 째 원소를 반드시 택했을 때의 최댓값
# 따라서 answer = max(DP[0]..DP[N-1])이 된다.
dp = [0] * N
dp[0] = v[0]

answer = v[0]
for i in range(1, N):
    maximum = v[i]
    for j in range(i):
        if v[j] < v[i]:
            maximum = max(maximum, dp[j] + v[i])
    dp[i] = maximum
    answer = max(answer, dp[i])

print(answer)
