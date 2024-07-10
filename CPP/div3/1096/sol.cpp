#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;
int answer = -101;
void calc(vector<vector<int>>& v) {
    int N = v.size();
    int M = v[0].size();
    if(N == 1 && M == 1) {
        return;  
    }
    for(int i = 1;i < N;i++) {
        //i 왼쪽을 기준으로 접기
        int left = i;
        int right = N-i;
        if(left <= right) {
            vector<vector<int>> ret(right,vector<int>(M));
            for(int k = 0;k < left;k++) {
                for(int j = 0;j < M;j++) {
                    ret[k][j] = v[i+k][j] + v[i-k-1][j];
                    answer = max(answer,ret[k][j]);
                }
            }
            for(int k = left;k < right;k++) {
                for(int j = 0;j < M;j++) {
                    ret[k][j] = v[k][j];
                }
            }
            calc(ret);
        } else {
            vector<vector<int>> ret(left,vector<int>(M));
            for(int k = 0;k < right;k++) {
                for(int j = 0;j < M;j++) {
                    ret[k][j] = v[i+k][j] + v[i-k-1][j];
                    answer = max(answer,ret[k][j]);
                }
            }
            for(int k = right;k < left;k++) {
                for(int j = 0;j < M;j++) {
                    ret[k][j] = v[i-k-1][j];
                }
            }
            calc(ret);
        }
    }
    for(int j = 1;j < M;j++) {
        //j 왼쪽을 기준으로 접기
        int left = j;
        int right = M-j;
        if(left <= right) {
            vector<vector<int>> ret(N,vector<int>(right));
            for(int k = 0;k < left;k++) {
                for(int i = 0;i < N;i++) {
                    ret[i][k] = v[i][j+k] + v[i][j-k-1];
                    answer = max(answer,ret[i][k]);
                }
            }
            for(int k = left;k < right;k++) {
                for(int i = 0;i < N;i++) {
                    ret[i][k] = v[i][k];
                }
            }
            calc(ret);
        } else {
            vector<vector<int>> ret(N,vector<int>(left));
            for(int k = 0;k < right;k++) {
                for(int i = 0;i < N;i++) {
                    ret[i][k] = v[i][j+k] + v[i][j-k-1];
                    answer = max(answer,ret[i][k]);
                }
            }
            for(int k = right;k < left;k++) {
                for(int i = 0;i < N;i++) {
                    ret[i][k] = v[i][j-k-1];
                }
            }
            calc(ret);
        }
    }
}

int main() {
    int N,M;
    cin >> N >> M;
    vector<vector<int>> paper(N,vector<int>(M));
    for(int i = 0;i < N;i++) for(int j = 0;j < M;j++) {
        cin >> paper[i][j];
        answer = max(answer,paper[i][j]);
    }
    calc(paper);
    cout<<answer;


    return 0;
}