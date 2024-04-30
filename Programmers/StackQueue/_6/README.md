
# 풀이

한 번 떨어져버린 주식 가격은 더 이상 순회할 필요가 없다.

따라서 떨어지지 않은 주식은 priority queue 에서 관리한다.

매 새로운 가격이 들어올 떄 마다 priority queue에서 위에서 부터 순회하면 죽은 주식을 골라낼 수 있다.
이 때 값은 죽은 날 - 들어온 날이다.

이렇게하면 Nlog N으로 풀이할 수 있다.

# 배운점