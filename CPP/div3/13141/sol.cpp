#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<iomanip>
using namespace std;
#define debug 0

int main() {
    int N,M; cin >> N >> M;
    vector<vector<int>> edges(M);
    vector<vector<int>> dist(N,vector<int>(N,INT_MAX));
    for(int i = 0;i < N;i++) dist[i][i] = 0;
    for(int m = 0;m < M;m++) {
        int S,E,L; cin >> S >> E >> L;
        S--;E--;
        edges[m] = {S,E,L};
        dist[S][E] = min(dist[S][E],L);
        dist[E][S] = min(dist[E][S],L);
    }
    for(int k = 0;k < N;k++) {
        for(int i = 0;i < N;i++) {
            if(k==i) continue;
            for(int j = 0;j < N;j++) {
                //i->j to i->k->j
                if(k==j || i==j) continue;
                if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    if(debug) {
        cout << "dist\n";
        for(int i = 0;i < N;i++) {
            for(int j = 0;j < N;j++) {
                if(dist[i][j] == INT_MAX) cout << "_ ";
                else cout << dist[i][j] << " ";
            }
            cout << endl;
        }
    }
    double answer = INT_MAX;
    for(int start = 0;start < N;start++) {
        //start 에서 시작
        double cur_max = 0;
        //모든 간선에 대해,,
        for(vector<int> edge : edges) {
            double this_max = 0;
            //간선 m이 불타는 데 걸리는 시간
            double timea = dist[start][edge[0]];
            double timeb = dist[start][edge[1]];
            if(abs(timea-timeb) >= edge[2]) this_max = max(timea,timeb);
            else {
                this_max = (timea + timeb + edge[2])/2;
            }
            cur_max = max(cur_max,this_max);
        }
        answer = min(answer,cur_max);
    }
    cout <<fixed<<setprecision(1)<< answer;
    return 0;
}