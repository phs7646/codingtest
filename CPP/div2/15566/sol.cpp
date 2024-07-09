#include<iostream>
#include<vector>

using namespace std;
int N,M;
vector<vector<int>> interest(15,vector<int>(4));
vector<pair<int,int>> prefer(15);
vector<vector<pair<int,int>>> edges(15);
vector<int> place(15,-1);
void dfs(int pos) {
    if(pos == N) {
        cout << "YES\n";
        for(int i = 0;i < N;i++) cout << place[i]+1 << " ";
        exit(0);
    }
    //pos의 개구리를 prefer.first에 배치
    int target = prefer[pos].first;
    //배치 가능한지 탐색
    bool flag = true;
    for(auto pair : edges[target]) {
        int T = pair.second;
        int frog = place[pair.first];
        if(frog == -1) continue; 
        if(interest[pos][T] != interest[frog][T]) {
            flag = false;
            break;
        }
    }
    if(flag) {
        place[target] = pos;
        //cout << "place " << pos << " to " << target << "\n";
        dfs(pos+1);
        //cout << "unplace " << pos << " to " << target << "\n";
        place[target] = -1;
    }

    //pos의 개구리를 prefer.second에 배치
    target = prefer[pos].second;
    if(target == -1) return;
    //배치 가능한지 탐색
    flag = true;
    for(auto pair : edges[target]) {
        int T = pair.second;
        int frog = place[pair.first];
        if(frog == -1) continue; 
        if(interest[pos][T] != interest[frog][T]) {
            flag = false;
            break;
        }
    }
    if(flag) {
        place[target] = pos;
        //cout << "place " << pos << " to " << target << "\n";
        dfs(pos+1);
        //cout << "unplace " << pos << " to " << target << "\n";
        place[target] = -1;
    }
    return;
}

int main() {
    //input
    cin >> N >> M;
    for(int i = 0;i < N;i++) for(int j = 0;j < 4;j++) cin >> interest[i][j];
    for(int i = 0;i < N;i++) {
        int a,b;
        cin >> a >> b;
        if(a == b) prefer[i] = {a-1,-1};
        else prefer[i] = {a-1,b-1};
    }
    for(int i = 0;i < M;i++) {
        int A,B,T;
        cin >> A >> B >> T;
        edges[A-1].push_back({B-1,T-1});
        edges[B-1].push_back({A-1,T-1});
    }
    //solve
    dfs(0);
    cout << "NO";

    return 0;
}