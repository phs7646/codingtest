#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <unordered_map>
using namespace std;

int N,P;

int stattoint(vector<bool> v) {
    int status = 0;
    for(bool b : v) {
        if(b) status = (status<<1) + 1;
        else status = status<<1; 
    }
    return status;
}

vector<bool> inttostat(int n) {
    vector<bool> ret(N);
    for(int i = 0;i < N;i++) {
        if((n & 1) == 1) ret[i] = true;
        n = (n>>1);
    }
    reverse(ret.begin(),ret.end());
    return ret;
}

int main() {

    cin >> N;
    vector<vector<int>> cost(N,vector<int>(N,0));
    for(int i = 0;i < N;i++)
        for(int j = 0;j < N;j++)
            cin >> cost[i][j];

    string s;
    cin >> s;
    int status = 0;
    for(char c : s) {
        if(c == 'Y') status = (status<<1) + 1;
        else status = status<<1;
    }

    cin >> P;
    if(P == 0) {
        cout << 0;
        return 0;
    }
    queue<pair<pair<int,int>,int>> q;

    unordered_map<int,int> memo;

    int num_alive = 0;
    for(bool b : inttostat(status)) if(b) num_alive++;

    if(num_alive == 0) {
        cout << -1;
        return 0;
    }

    q.push({{status,1},P-num_alive});

    int answer = INT_MAX;
    while(!q.empty()) {
        pair<pair<int,int>,int> pair = q.front();
        q.pop();
        int stat = pair.first.first;
        int current = pair.first.second;
        int togo = pair.second;
        if(memo[stat] > 0 && memo[stat] < current) continue;
        vector<bool> statv = inttostat(stat);
        if(togo <= 0) {
            if(answer > current) answer = current;
            continue;
        }

        for(int i = 0;i < N;i++) {
            if(statv[i] == false) {
                //find minimum cost to turn on
                int min_cost_index = -1;
                for(int j = 0; j < N;j++) {
                    if(statv[j] == true && (min_cost_index == -1 || cost[min_cost_index][i] > cost[j][i])) {
                        min_cost_index = j;
                    }  
                }
                if(min_cost_index != -1) {
                    vector<bool> newv(N);
                    for(int i = 0;i < N;i++) newv[i] = statv[i];
                    newv[i] = true;
                    int new_cost = current+cost[min_cost_index][i];
                    int new_stat = stattoint(newv);
                    if(memo[new_stat] == 0 || memo[new_stat] > new_cost) {
                        memo[new_stat] = new_cost;
                        q.push({{new_stat,new_cost},togo-1});
                    }

                }
            }
        }

    }
    if(answer == INT_MAX) cout << -1;
    else cout << answer-1;


    return 0;
}