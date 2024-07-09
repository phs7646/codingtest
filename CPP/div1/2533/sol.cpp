#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

vector<int> memo;
vector<vector<int>> conn;
vector<bool> visited;

int dp(int pos) {
    if(memo[pos] != 0) {
        return memo[pos];
    }
    visited[pos] = true;
    vector<int> childs;
    for(int target : conn[pos]) {
        if(!visited[target]) childs.push_back(target);
    }
    if(childs.empty()) return 0;
    int ret = INT_MAX;
    //pick pos + sum(subtree)
    int current = 1;
    for(int child : childs) current += dp(child);
    ret = min(ret,current);
    //do not pick pos -> must pick childs
    current = 0;
    for(int child : childs) {
        vector<int> childsofchild;
        for(int target : conn[child]) if(!visited[target])childsofchild.push_back(target);
        int tmp = 1;
        for(int childofchild : childsofchild) tmp += dp(childofchild);
        current += tmp;
    }
    ret = min(ret,current);
    memo[pos] = ret;
    visited[pos] = false;
    return ret;
}

int main() {
    int N;
    cin >> N;
    conn.resize(N);
    visited.resize(N);
    memo.resize(N);
    for(int i = 0;i < N-1;i++) {
        int a,b;
        cin >> a >> b;
        conn[a-1].push_back(b-1);
        conn[b-1].push_back(a-1);
    }
    cout << dp(0);
    //for(int m : memo) cout << m << " ";
    //cout << "\n";
    
    return 0;
}