#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;
int answer = -101;
void calc(vector<vector<int>>& v, int si, int sj, int N,int M) {
    if(N==1 && M==1) return;
    for(int i = 1;i <= N;i++) {
        vector<vector<int>> origin = v;
        int left = i;
        int right = N-i;
        int calcul = min(left,right);
        for(int k = 0;k < calcul;k++) {
            for(int j = 0;j < M;j++) {
                origin[si+i+k][sj+j] += origin[si+i-1-k][sj+j];
                answer = max(answer,origin[si+i+k][sj+j]);
            }
        }
        calc(origin,si+i,sj,N-i,M);
    }
    for(int j = 1;j <= M;j++) {
        vector<vector<int>> origin = v;
        int left = j;
        int right = M-j;
        int calcul = min(left,right);
        for(int k = 0;k < calcul;k++) {
            for(int i = 0;i < N;i++) {
                origin[si+i][sj+j+k] += origin[si+i][sj+j-1-k];
                answer = max(answer,origin[si+i][sj+j+k]);
            }
        }
        calc(origin,si,sj+j,N,M-j);
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
    calc(paper,0,0,N,M);
    cout<<answer;


    return 0;
}