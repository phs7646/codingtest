#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

pair<int,int> P[2000];
vector<pair<int,pair<int,int>>> D;
int used[2000];
int main() {
    int N,C;
    cin >> N >> C;
    for(int i = 0;i < N;i++) {
        int X,Y;
        cin >> X >> Y;
        P[i] = make_pair(X,Y);
    }
    for(int i = 0;i < N;i++) {
        for(int j = i+1;j < N;j++) {
            int dist = pow(P[i].first - P[j].first,2) + pow(P[i].second - P[j].second,2);
            if(dist < C) continue;
            D.push_back(make_pair(dist,make_pair(i,j)));
        }
    }
    sort(D.begin(),D.end());
    used[0] = 1;
    int cost = 0;
    int count = 1;
    while(1) {
        int prev_count = count;
        for(pair<int,pair<int,int>> t : D) {
            int a = t.second.first;
            int b = t.second.second;
            if(used[a] + used[b] == 1) {
                used[a] = used[b] = 1;
                cost += t.first;
                count++;
                break;
            }
        }
        if(count == N) break;
        if(prev_count == count) {
            cout << -1 << "\n";
            return 0;
        }
    }
    cout << cost << "\n";
    return 0;
}