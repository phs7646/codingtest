#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;
typedef pair<int,int> pp;
int N,K;
vector<vector<pp>> points;
int answer = 1e9;

void dfs(int k,int i1, int i2,int j1,int j2,int area) {
    if(k==K) {
        answer = area;
        return;
    }

    //k색을 가진 점 하나를 고른다
    for(pp p : points[k]) {
        //dfs
        int a = min(i1,p.first);
        int b = max(i2,p.first);
        int c = min(j1,p.second);
        int d = max(j2,p.second);
        int area = (b-a)*(d-c);
        if(area < answer) dfs(k+1,a,b,c,d,area);
    }
}


int main(int argc, char** argv) {
    cin>>N>>K;
    points.resize(K);
    for(int i = 0;i < N;i++) {
        int a,b,c; cin>>a>>b>>c;
        points[c-1].emplace_back(a,b);
    }
    for(pp p : points[0]) {
        dfs(1,p.first,p.first,p.second,p.second,0);
    }
    cout << answer;

    return 0;
}