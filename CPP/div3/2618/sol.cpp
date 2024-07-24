#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

int dist(pair<int,int> p1, pair<int,int> p2) {
    return abs(p1.first-p2.first) + abs(p1.second-p2.second);
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int N,W; cin >> N >> W;
    vector<vector<int>> dp(1001,vector<int>(1001,INT_MAX));
    vector<vector<pair<int,int>>> history(1001,vector<pair<int,int>>(1001));
    dp[0][0] = 0;
    pair<int,int> base1 = {1,1};
    pair<int,int> base2 = {N,N};
    vector<pair<int,int>> works(W+1);
    for(int w = 1;w <= W;w++) {
        int y,x; cin >> y >> x;
        works[w] = {y,x};
    }
    dp[1][0] = dist(works[1],base1);
    history[1][0] = {0,0};
    dp[0][1] = dist(works[1],base2);
    history[0][1] = {0,0};
    for(int w = 2;w <= W;w++) {
        //w번째 일을 처리하자
        //dp[w][...] 과 dp[...][w] 를 계산해야함!
        //둘중 하나가 w-1인것만 계산에 사용됨
        for(int i = 0;i < w-1;i++) {
            //dp[i][w-1] 에서 연산
            //dp[w][w-1] 업데이트
            int newdist = dp[i][w-1];
            if(i == 0) newdist += dist(base1,works[w]);
            else newdist += dist(works[i],works[w]);
            //dp[w][w-1] = min(dp[w][w-1],newdist);
            if(newdist < dp[w][w-1]) {
                dp[w][w-1] = newdist;
                history[w][w-1] = {i,w-1};
            }
            //dp[i][w] 업데이트
            newdist = dp[i][w-1] + dist(works[w],works[w-1]);
            //dp[i][w] = min(dp[i][w],newdist);
            if(newdist < dp[i][w]) {
                dp[i][w] = newdist;
                history[i][w] = {i,w-1};
            }
        }
        for(int j = 0;j < w-1;j++) {
            //dp[w-1][j] 에서 연산
            //dp[w-1][w] 업데이트
            int newdist = dp[w-1][j];
            if(j == 0) newdist += dist(base2,works[w]);
            else newdist += dist(works[j],works[w]);
            //dp[w-1][w] = min(dp[w-1][w],newdist);
            if(newdist < dp[w-1][w]) {
                dp[w-1][w] = newdist;
                history[w-1][w] = {w-1,j};
            }
            //dp[w][j] 업데이트
            newdist = dp[w-1][j] + dist(works[w],works[w-1]);
            //dp[w][j] = min(dp[w][j],newdist);
            if(newdist < dp[w][j]) {
                dp[w][j] = newdist;
                history[w][j] = {w-1,j};
            }
        }
    }
    int answer = INT_MAX;
    pair<int,int> final_history;
    for(int i = 0;i < W;i++) {
        //answer = min(answer,min(dp[W][i],dp[i][W]));
        if(dp[W][i] < answer) {
            answer = dp[W][i];
            final_history = {W,i};
        }
        if(dp[i][W] < answer) {
            answer = dp[i][W];
            final_history = {i,W};
        }
    }
    cout << answer << endl;
    vector<int> answer_history;
    pair<int,int> cur_history = final_history;
    for(int step = W;step > 0;step--) {
        if(cur_history.first == step) answer_history.push_back(1);
        else answer_history.push_back(2);
        cur_history = history[cur_history.first][cur_history.second];
    }
    for(int i = W-1;i >= 0;i--) cout << answer_history[i] << "\n";
    return 0;
}