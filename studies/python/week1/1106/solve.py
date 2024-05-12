
C, N = map(int,input().split())

cities = []
m = 0
m_a = 0
m_b = 0 #m은 최고 효율로 광고하는 도시
for _ in range(N) :
    a, b = map(int,input().split())
    cities.append((a,b))
    if b/a > m :
        m = a/b
        m_a = a
        m_b = b

possible_max = (C + b - 1) // b * a # 배열의 길이는 최고 효율인 도시에서 모두 모집할 때 드는 비용


dp = [0] * (possible_max+ 1) # dp[i] : i원을 사용했을 때 얻을 수 있는 최대 고객 수
dp[possible_max] = C
for cost in range(0,possible_max+1) :
    for a,b in cities :
        if cost + a <= possible_max :
            dp[cost+a] = max(dp[cost+a],dp[cost] + b) # a원을 주고 b를 고름

for index,value in enumerate(dp) :
    if value >= C :
        print(index)
        break
