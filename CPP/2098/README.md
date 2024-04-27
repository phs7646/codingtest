4월 27일

문제 출처 : https://www.acmicpc.net/problem/2098

소요 시간 : 약 2시간

난이도 : 골드 1

키워드 : 비트마스킹, DP

유명한 문제라고 해서 간단할 줄 알았는데 엄청 고생했다.
비트마스킹을 활용해서 풀어야 된다는 생각은 빨리 떠올랐다.

하지만 결국 거의 완전탐색에 가까운 탐색을 해야하고, 각 탐색에서 시간을 단축하기 위해 DP를 사용한다는 발상이 재밌었다.
(각 단계에서 DP에 저장하는 값이 계산이 끝난 값이 아님)

그리고 여태까지 대부분의 비트마스킹 문제에서 mask가 항상 마지막 차원에 들어갔었는데,
mask를 첫 차원으로 놓고 mask의 상황에서 다시 N^2으로 모든 상황을 탐색하는 것이 떠올리기 힘들었다.(N이 16이라 이런것도 가능한가보다)

그외 반례처리는 간단해서 다행이었다.