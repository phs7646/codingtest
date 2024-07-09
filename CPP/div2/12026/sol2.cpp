#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<climits>

using namespace std;

int main() {
    int N;
    cin >> N;
    string s;
    cin >> s;
    vector<int> answer(N,INT_MAX);
    answer[0] = 0;
    for(int i = 1;i < N;i++) {
        char prev = 'B';
        if(s[i] == 'J') prev = 'O';
        else if(s[i] == 'B') prev = 'J';
        for(int j = 0;j < i;j++) {
            if(prev != s[j]) continue;
            if(answer[j] == INT_MAX) continue;
            answer[i] = min(answer[i],answer[j] + (i-j)*(i-j));
        }
    }
    if(answer[N-1] == INT_MAX) cout << -1;
    else cout << answer[N-1];
    return 0;
}