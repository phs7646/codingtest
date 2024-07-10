#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

int N,M;
set<int> hori_case;
set<int> vert_case;

void search_hori(vector<int>& v,int s,int w) {
    for(int i = s;i < s+w;i++) hori_case.insert(v[i]);
    if(w == 1) return;
    for(int i = 1;i < w;i++) {
        vector<int> v2 = v;
        //s+i 를 기준으로 접기
        int left = i;
        int right = w-i;
        if(left <= right) {
            //왼쪽을 접기
            for(int k = 0;k < left;k++) {
                v2[s+i+k] |= v2[s+i-k-1];
            }
            search_hori(v2,s+left,w-left);
        } else {
            //오른쪽을 접기
            for(int k = 0;k < right;k++) {
                v2[s+i-k-1] |= v2[s+i+k];
            }
            search_hori(v2,s,w-right);
        }
    }
}
void search_vert(vector<int>& v,int s,int w) {
    for(int i = s;i < s+w;i++) vert_case.insert(v[i]);
    if(w == 1) return;
    for(int i = 1;i < w;i++) {
        vector<int> v2 = v;
        //s+i 를 기준으로 접기
        int left = i;
        int right = w-i;
        if(left <= right) {
            //왼쪽을 접기
            for(int k = 0;k < left;k++) {
                v2[s+i+k] |= v2[s+i-k-1];
            }
            search_vert(v2,s+left,w-left);
        } else {
            //오른쪽을 접기
            for(int k = 0;k < right;k++) {
                v2[s+i-k-1] |= v2[s+i+k];
            }
            search_vert(v2,s,w-right);
        }
    }
}


int main() {
    cin >> N >> M;
    vector<int> horizon(N);
    for(int i = 0;i < N;i++) horizon[i] = (1<<i);
    vector<int> vertic(M);
    for(int j = 0;j < M;j++) vertic[j] = (1<<j);

    search_hori(horizon,0,N);
    search_vert(vertic,0,M);
    
    vector<vector<int>> board(N,vector<int>(M));
    for(int i = 0;i < N;i++) for(int j = 0;j < M;j++) cin >> board[i][j];
    int answer = -101;
    for(int hori_bit : hori_case) {
        vector<int> values(M);
        for(int i = 0;i < N;i++) {
            if(hori_bit & (1<<i)) {
                for(int j = 0;j < M;j++) {
                    values[j] += board[i][j];
                }
            }
        }
        for(int vert_bit : vert_case) {
            int cur = 0;
            for(int j = 0;j < M;j++) if(vert_bit & (1<<j)) cur += values[j];
            answer = max(answer,cur);
        }
        
    }
    
    cout << answer;

    return 0;
}