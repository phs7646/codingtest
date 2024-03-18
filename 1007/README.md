3월 14일

문제 출처 : https://www.acmicpc.net/problem/1007

소요 시간 : 약 1시간

난이도 : 골드 2

키워드 : Brute Force, 수학

처음에 "벡터의 합의 길이" 를 "벡터의 길이의 합" 으로 이해해서 잘못풀었다(sol.cpp).

이후 수학적인 고민 (모든 벡터를 검사할 필요가 없고, N개의 포인트중 절반은 더해지고 절반은 빼주면 된다)에 시간 소요했다.

계속 double을 정수까지만 프린트하길래 구글링을 통해 <iomanip> 헤더의 fixed 및 setprecision을 찾았다.