5월 6일

문제 출처 : https://www.acmicpc.net/problem/17182

소요 시간 : 약 25분

난이도 : 골드 3

키워드 : 플로이드워셜, 비트마스킹, DP

DP 아이디어는 너무 깔끔하게 나왔다.

다만 각 행성 사이의 거리가 다른 행성을 거쳐갈 때 더 짧을 수 있기 때문에 이 부분을 먼저 계산해서 최솟값을 보장해줘야 한다.

이 때문에 i->j로 갈 때 모든 대체 경로 i->k->j 를 비교해서 최솟값을 넣어주는 부분을 넣었다. (이 부분이 플로이드 워셜 이었다)  
