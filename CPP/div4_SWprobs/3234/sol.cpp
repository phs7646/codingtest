#include<iostream>

using namespace std;

int N;
int arr[9];
bool visited[9];
long long answer;
int sum;
int _exp[]={1,2,4,8,16,32,64,128,256,512};
long long factorial[10] = {1,1,2,6,24,120,720,5040, 40320,362880};
void dfs(int pos, int cur_left, int cur_right) {
    if(pos == N) {
        answer++;
        return;
    }
    if(cur_left >= sum - cur_left) {
        answer += factorial[N-pos] * _exp[N-pos]; 
        return;
    }
    
    for(int i = 0; i < N; i++) {
        if(!visited[i]) {
            visited[i] = true;
            dfs(pos + 1, cur_left + arr[i], cur_right);
            if(cur_right + arr[i] <= cur_left) dfs(pos + 1, cur_left, cur_right + arr[i]);
            visited[i] = false;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int T; cin >> T;
    for(int t = 1; t <= T; t++) {
        //initialize
        answer = 0;
        sum = 0;
        for(int i = 0;i < N;i++) visited[i] = false;

        //input
        cin >> N;
        for(int i = 0; i < N; i++) {
            cin >> arr[i];
            sum += arr[i];
        }

        //logic
        dfs(0, 0, 0);

        //출력
        cout << '#' << t << ' ' << answer << '\n';
    }
    return 0;
}
