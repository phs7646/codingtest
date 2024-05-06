#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int main() {
    int N,M;
    cin >> N >> M;
    int Tg,Tb,X,B;
    cin >> Tg >> Tb >> X >> B;
    vector<string> map(N);
    vector<vector<int>> safety(N,vector<int>(M,1));
    queue<pair<int,int>> virus;
    for(int i = 0;i < N;i++) {
        cin>>map[i];
        for(int j = 0;j < M;j++) {
            if(map[i][j] == '#') safety[i][j] = -1;
            if(map[i][j] == '*') {
                safety[i][j] = 0;
                virus.push({i,j});
            }
        }
    }
    queue<vector<int>> buildings;

    int stage = 0;
    while(stage < Tg) {
        while(!buildings.empty() && stage - buildings.front()[0] == Tb+1) {
            safety[buildings.front()[1]][buildings.front()[2]] = 0;
            virus.push({buildings.front()[1],buildings.front()[2]});
            buildings.pop();
        }
        int qsize = virus.size();
        for(int v = 0;v < qsize;v++) {
            auto pair = virus.front();
            int i = pair.first;
            int j = pair.second;
            virus.pop();
            vector<std::pair<int,int>> cand = {{i-1,j},{i+1,j},{i,j-1},{i,j+1}};
            for(auto c : cand) {
                int y = c.first;
                int x = c.second;
                if(y < 0 || y >= N || x < 0 || x >= M) continue;
                if(safety[y][x] == -1) {
                    buildings.push({stage,y,x});
                    safety[y][x] = -2;
                } else if(safety[y][x] == 1) {
                    safety[y][x]--;
                    virus.push({y,x});
                }
            }
        }
        stage++;
        
        /*
        cout << stage << " stage\n";
        for(int i = 0;i < N;i++) {
            for(int j = 0;j < M;j++) {
                cout << safety[i][j] << " ";
            }
            cout << "\n";
        }
        */
        
        
    }
    while(!buildings.empty() && stage - buildings.front()[0] == Tb+1) {
        safety[buildings.front()[1]][buildings.front()[2]] = 0;
        virus.push({buildings.front()[1],buildings.front()[2]});
        buildings.pop();
    }
    vector<pair<int,int>> answer;
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < M;j++) {
            if(safety[i][j] == 1 || safety[i][j] == -1 || safety[i][j] == -2) answer.push_back({i,j});
        }
    }
    if(answer.empty()) cout << -1;
    else {
        for(auto pair : answer) {
            cout << pair.first+1 << " " << pair.second+1 << "\n";
        }
    }
    
    return 0;
}
