5월 4일

문제 출처 : https://www.acmicpc.net/problem/1017

소요 시간 : 약 2시간

난이도 : 플래티넘 3

키워드 : 이분 매칭

dfs로 어떻게 잘 해볼려다가 도저히 시간초과가 나서 결국 태그에 있는 이분 매칭에 대해 공부했다.

꽤 난이도 있는 개념이었는데 고생해서 이해할 수 있었다.

핵심은 다음과 같다.

1. 홀수 -> 짝수, 또는 짝수 -> 홀수의 방향으로만 매칭이 가능하다 (아래에서 전자로 가정)

2. 따라서 해당 짝수가 매칭이 어디로 되어있는지를 추적한다(matching)

3. 맨 처음은 0와 연결될 수 있는 수들(adj[0]) 과 0를 매칭한다.

4. 그 후 모든 홀수에 대해 매칭을 시도한다.

5. 만약 홀수의 인접 짝수가 매칭되지 않았다면 바로 매칭하고 성공으로 종료한다.

6. 만약 이미 매칭되어 있다면 해당 짝수와 매칭된 홀수가 혹시 다른 짝수와 매칭이 되는지 알아본다.

7. 다른 짝수와 매칭이 된다면 그렇게 한 다음 현재 홀수를 그 짝수와 매칭하고 성공으로 종료한다.

= 즉, 매 홀수가 추가될 때마다 기존의 매칭들을 이리저리 바꿔가며 해당 홀수가 매칭 가능한지를 판단하는 것이다.

8. 만약 마지막 홀수가 매칭에 성공했다면 해당 케이스는 이분 매칭이 가능한 것이다.

= 한번의 매칭에서 동일한 정점이 두번 반복될 필요는 없다 (즉, 매칭을 위해 기존에 매칭된 홀수 i의 다른 매칭을 찾는데 실패했다면, 앞으로는 다시 i에 갈 필요가 없다. 반드시 i는 기존 상태로 매칭되어야 한다)


알고리즘 자체가 상당히 세련됐다는 느낌이다. 재귀 함수가 실제로 매칭을 시키고 성공 여부를 반환하기 때문에 코드가 매우 간결한데 실제로는 복잡한 매칭 과정을 진행하게 된다. 기본적인 dfs보다 활용하는 정보의 양이 훨씬 많고 탐색 수도 많이 줄어든다.

하지만 이분 매칭 자체는 상당히 제한된 상황에서만 사용가능할 것 같다.