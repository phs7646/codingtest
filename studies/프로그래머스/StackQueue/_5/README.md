
# 풀이

문제 상황이 복잡하고 처음에 한번에 이해가 안돼서 코드를 두 번 작성했다.

문제 상황을 그대로 구현했다.

on_bridge에 올라가 있는 트럭들의 {무게, 올라간 시간}을 푸쉬한다. 현재 시간과 올라간 시간을 비교해서 pop 시점을 확인한다.

이 때 올라간 시간은 모두 다름으로 한번에 하나의 트럭만 push되고, pop될 수 있다.

다리가 가득차면 다음 pop까지 시간을 스킵했다.

# 배운점