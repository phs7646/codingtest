#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

/*
1부터 200까지 cycle simulation 결과 열 : k , 행 : x
1 2 4 8 
1 3 6
1 2 5
1 2 4 8
1 3 6
1 2 5
1 2 4 8
1 3 6
1 2 5
1 2 4 8
1 3 6
1 2 5
1 2 4 8
1 3 7
1 2 5
1 2 4 9
1 3 7
1 2 5
1 2 4 9
1 3 7
1 2 5
1 2 4 9
1 3 7
1 3 6
1 2 4 9
1 3 7
1 3 6
1 2 4 9
1 3 7
1 3 6
1 2 5
1 2 4 8
1 3 6
1 2 5
1 2 4 8
1 3 6
1 2 5
1 2 4 8
1 3 6
1 2 5
1 2 4 8
1 3 6
1 2 5
1 2 4 8
1 3 7
1 2 5
1 2 4 9
1 3 7
1 2 5
1 2 4 9
1 3 7
1 2 5
1 2 4 9
1 3 7
1 3 6
1 2 4 9
1 3 7
1 3 6
1 2 5
1 2 4 8
*/

//가정 1 : 200 이후에도 위와 동일한 사이클만 존재한다 (맞는 것 같음)

/* 풀이 1
cycle이 끝나는 n 과 k를 알면
k개의 cycle에 총 n개의 element가 담겨있고,
모든 사이클에서 4가 아닌 수가 3개씩 존재함으로,
n - 3k로 4의 갯수를 구할 수 있다
*/

/* 풀이 2
현재 n은 cycle이 끝나는 n이 아님. x를 통해 이전 cycle이 끝나는 n을 찾고,
마지막 cycle은 수동으로 더해준다
*/

int main() {
    long long n,k,x;
    cin >> n >> k >> x;
    //2^0부터 시작하므로, element는 n+1개가 있다
    n++;
    int num_to_go[] = {0,1,2,2,3,3,3,3,4,4};
    long long last_n = n - num_to_go[x];
    long long ret = last_n - 3*(k-1); //이전까지의 싸이클
    //현재 싸이클에 4가 포함되어있는가 ? = 4,8,9
    if(x == 4 || x == 8 || x == 9) ret++;
    cout << ret;
    return 0;
}