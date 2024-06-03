#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main() {
    int N,K;
    cin >> N >> K;
    vector<pair<int,int>> v(N);
    for(int i = 0;i < N;i++) {
        int a,b;
        cin >> a >> b;
        v[i] = {b,a};
    }
    sort(v.begin(),v.end());
    queue<pair<int,int>> active;
    int answer = 0;
    int current = 0;
    for(auto pair : v) {
        int x = pair.first;
        int g = pair.second;
        //push new ice
        current += g;
        active.push({x,g});
        //pop old ice
        int minimal = x - 2 * K;
        while(!active.empty() && active.front().first < minimal) {
            current -= active.front().second;
            active.pop();
        }
        //update
        answer = max(answer,current);
    }

    cout << answer;
    return 0;
}