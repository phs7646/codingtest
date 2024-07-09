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
    queue<pair<int,int>> q;
    q.push({0,0});
    vector<int> answer(N,INT_MAX);
    while(!q.empty()) {
        auto pair = q.front();
        q.pop();
        int pos = pair.first;
        int cur = pair.second;
        if(answer[pos] < cur) continue;
        char nextblock = 'O';
        if(s[pos] == 'O') nextblock = 'J';
        else if(s[pos] == 'J') nextblock = 'B';

        for(int newpos = pos+1;newpos < N;newpos++) {
            if(s[newpos] != nextblock) continue;
            //cout << "Jump from " << pos << " to " << newpos << endl;
            int newcost = cur+(newpos-pos)*(newpos-pos);
            if(answer[newpos] <= newcost) continue;
            answer[newpos] = newcost;
            if(newpos < N-1) q.push({newpos,newcost});
        }
    }
    if(answer[N-1] == INT_MAX) cout << -1;
    else cout << answer[N-1];
    return 0;
}