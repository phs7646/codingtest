#include<iostream>
#include<queue>
#include<string>
using namespace std;
typedef pair<int,int> pp;
string map[100];
bool visited1[100][100];
bool visited2[100][100];
pp moves[] = {{0,1},{1,0},{-1,0},{0,-1}};
int main() {
    int N; cin >> N;
    for(int i = 0;i < N;i++) cin >> map[i];

    //normal
    int ans1 = 0;
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < N;j++) {
            if(visited1[i][j]) continue;
            ans1++;
            char c = map[i][j];
            queue<pp> q;
            visited1[i][j] = true;
            q.emplace(i,j);
            while(!q.empty()) {
                pp cur = q.front(); q.pop();
                for(int d = 0;d < 4;d++) {
                    int ny = cur.first + moves[d].first;
                    int nx = cur.second + moves[d].second;
                    if(0 <= nx && nx < N && 0 <= ny && ny < N && map[ny][nx] == c && !visited1[ny][nx]) {
                        visited1[ny][nx] = true;
                        q.emplace(ny,nx);
                    }
                }
            }
        }
    }

    //other
    int ans2 = 0;
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < N;j++) {
            if(visited2[i][j]) continue;
            ans2++;
            char c = map[i][j];
            queue<pp> q;
            visited2[i][j] = true;
            q.emplace(i,j);
            while(!q.empty()) {
                pp cur = q.front(); q.pop();
                for(int d = 0;d < 4;d++) {
                    int ny = cur.first + moves[d].first;
                    int nx = cur.second + moves[d].second;
                    if(0 <= nx && nx < N && 0 <= ny && ny < N && !visited2[ny][nx]) {
                        if(c == map[ny][nx] || (c == 'R' && map[ny][nx] == 'G') || (c=='G' && map[ny][nx] == 'R')) {
                            visited2[ny][nx] = true;
                            q.emplace(ny,nx);
                        }
                    }
                }
            }
        }
    }

    cout << ans1 << " " << ans2;

    return 0;
}