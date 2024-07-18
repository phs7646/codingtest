#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N;
int map[100][100];
queue<pair<int,int>> bodies;
int headi,headj;
int dir = 1;
pair<int,int> moves[4] = {{-1,0},{0,1},{1,0},{0,-1}};

void PrintMap() {
    cout << "-----------------------\n";
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < N;j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-----------------------\n";
}

bool sim() {
    //move head
    headi += moves[dir].first;
    headj += moves[dir].second;
    if(0 > headi || headi >= N || 0 > headj || headj >= N) return false; //wall
    if(map[headi][headj] == 2) return false; //body
    
    //eat apple
    if(map[headi][headj] != 1) {
        //no apple
        pair<int,int> tail = bodies.front();
        bodies.pop();
        map[tail.first][tail.second] = 0;
    }
    //gogo
    map[headi][headj] = 2;
    bodies.push({headi,headj});
    return true;
}

int main() {
    bodies.push({0,0});
    cin >> N;
    int K; cin >> K;
    map[0][0] = 2; //body
    for(int i = 0;i < K;i++) {
        int a,b;
        cin >> a >> b;
        map[a-1][b-1] = 1; //apple
    }
    int L; cin >> L;
    vector<pair<int,bool>> changes(L);
    for(int i = 0;i < L;i++) {
        int a; char c;
        cin >> a >> c;
        changes[i] = {a,c=='L'};
    }
    changes.push_back({changes[L-1].first + 101,true});
    int time = 0;
    //cout << time;
    //PrintMap();
    for(pair<int,bool> inst : changes) {
        //time까지 진행
        while(time < inst.first) {
            if(!sim()) {
                cout << time+1;
                exit(0);
            }
            time++;
            //cout << time;
            //PrintMap();
        }
        //dir변경
        if(inst.second) dir = (dir-1+4)%4;
        else dir = (dir+1)%4;
    }

    return 0;
}