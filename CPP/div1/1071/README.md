4월 22일

문제 출처 : https://www.acmicpc.net/problem/1071

소요 시간 : 약 20분

난이도 : 플래티넘 5

키워드 : 수학

꽤 재밌는 정렬 문제였다. 그리디 하게 가능한 값을 넣다가 불가능한 경우에 되돌아가야 하는데, 
처음에 이를 백트래킹으로 구현할까 생각했다가 깊이가 너무 깊어질 것 같아 반복문으로 하려고 노력했다.

bool 변수 flag를 마치 오버플로우 체크처럼 켰다 끄면서 되돌아갈 필요가 있을 때 되돌아가줬다.
참신한 아이디어였던 것 같고 덕분에 코드도 매우 간결하고 빠른 시간안에 푼 것 같다.
