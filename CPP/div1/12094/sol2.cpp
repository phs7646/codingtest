#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//벡터 복사를 줄여보자.. update함수내에서 tmp를 만들지말고 기존 벡터에서 바로 진행?
//left right 완료, up down도 ret없이 가능할듯.
//방향 함수에서 변화 여부를 미리 감지하자 (만약 첫번째 라인에서 변화가 있었따면 이후에는 변화감지 x)
/* helper functions */

/* codes */
int N;

bool left(vector<vector<int>>& v,int& maxvalue) {
    bool ret = false;
    for(int i = 0; i < N;i++) {
        int pos = 0;
        for(int pivot = 0;pivot < N;pivot++) {
            if(v[i][pivot] == 0) continue;
            int next = pivot+1;
            while(next < N && v[i][next] == 0) next++;
            if(next < N) {
                if(v[i][next] == v[i][pivot]) {
                    //next가 존재하고 값이 같음. 합치기
                    v[i][pos] = v[i][pivot] << 1 ;
                    maxvalue = max(maxvalue, v[i][pos]);
                    pos++;
                    ret = true;
                    pivot = next;
                } else {
                    //next가 존재하지만 값이 다름. pivot만 등록
                    if(v[i][pos] != v[i][pivot]) {
                        v[i][pos] = v[i][pivot];
                        ret = true;
                    }
                    pos++;
                    pivot = next-1;
                }
            } else {
                //next가 존재하지 않음. pivot만 등록
                if(v[i][pos] != v[i][pivot]) {
                    v[i][pos] = v[i][pivot];
                    ret = true;
                }
                pos++;
                break;
            }
        }
        for(;pos < N;pos++) {
            if(v[i][pos] != 0) {
                v[i][pos] = 0;
                ret = true;
            }
        }
    }
    return ret;
}

bool right(vector<vector<int>>& v,int& maxvalue) {
    bool ret = false;
    for(int i = 0; i < N;i++) {
        int pos = N-1;
        for(int pivot = N-1;pivot >= 0;pivot--) {
            if(v[i][pivot] == 0) continue;
            int next = pivot-1;
            while(next >= 0 && v[i][next] == 0) next--;
            if(next >= 0) {
                if(v[i][next] == v[i][pivot]) {
                    //next가 존재하고 값이 같음. 합치기
                    v[i][pos] = v[i][pivot] << 1 ;
                    maxvalue = max(maxvalue, v[i][pos]);
                    pos--;
                    ret = true;
                    pivot = next;
                } else {
                    //next가 존재하지만 값이 다름. pivot만 등록
                    if(v[i][pos] != v[i][pivot]) {
                        v[i][pos] = v[i][pivot];
                        ret = true;
                    }
                    pos--;
                    pivot = next+1;
                }
            } else {
                //next가 존재하지 않음. pivot만 등록
                if(v[i][pos] != v[i][pivot]) {
                    v[i][pos] = v[i][pivot];
                    ret = true;
                }
                pos--;
                break;
            }
        }
        for(;pos >= 0;pos--) {
            if(v[i][pos] != 0) {
                v[i][pos] = 0;
                ret = true;
            }
        }
    }
    return ret;
}

bool up(vector<vector<int>>& v,int& maxvalue) {
    bool ret = false;
    for(int i = 0; i < N;i++) {
        int pos = 0;
        for(int pivot = 0;pivot < N;pivot++) {
            if(v[pivot][i] == 0) continue;
            int next = pivot+1;
            while(next < N && v[next][i] == 0) next++;
            if(next < N) {
                if(v[next][i] == v[pivot][i]) {
                    //next가 존재하고 값이 같음. 합치기
                    v[pos][i] = v[pivot][i] << 1 ;
                    maxvalue = max(maxvalue, v[pos][i]);
                    pos++;
                    ret = true;
                    pivot = next;
                } else {
                    //next가 존재하지만 값이 다름. pivot만 등록
                    if(v[pos][i] != v[pivot][i]) {
                        v[pos][i] = v[pivot][i];
                        ret = true;
                    }
                    pos++;
                    pivot = next-1;
                }
            } else {
                //next가 존재하지 않음. pivot만 등록
                if(v[pos][i] != v[pivot][i]) {
                    v[pos][i] = v[pivot][i];
                    ret = true;
                }
                pos++;
                break;
            }
        }
        for(;pos < N;pos++) {
            if(v[pos][i] != 0) {
                v[pos][i] = 0;
                ret = true;
            }
        }
    }
    return ret;
}
bool down(vector<vector<int>>& v,int& maxvalue) {
    bool ret = false;
    for(int i = 0; i < N;i++) {
        int pos = N-1;
        for(int pivot = N-1;pivot >= 0;pivot--) {
            if(v[pivot][i] == 0) continue;
            int next = pivot-1;
            while(next >= 0 && v[next][i] == 0) next--;
            if(next >= 0) {
                if(v[next][i] == v[pivot][i]) {
                    //next가 존재하고 값이 같음. 합치기
                    v[pos][i] = v[pivot][i] << 1 ;
                    maxvalue = max(maxvalue, v[pos][i]);
                    pos--;
                    ret = true;
                    pivot = next;
                } else {
                    //next가 존재하지만 값이 다름. pivot만 등록
                    if(v[pos][i] != v[pivot][i]) {
                        v[pos][i] = v[pivot][i];
                        ret = true;
                    }
                    pos--;
                    pivot = next+1;
                }
            } else {
                //next가 존재하지 않음. pivot만 등록
                if(v[pos][i] != v[pivot][i]) {
                    v[pos][i] = v[pivot][i];
                    ret = true;
                }
                pos--;
                break;
            }
        }
        for(;pos >= 0;pos--) {
            if(v[pos][i] != 0) {
                v[pos][i] = 0;
                ret = true;
            }
        }
    }
    return ret;
}

int answer = 0;


void solve(vector<vector<int>>& board,int current, int depth) {
    answer = max(answer,current);
    if(depth == 0) return;
    int possible_maximum = (current << depth);
    if(answer >= possible_maximum) return;

    vector<vector<int>> backup = board;
    int backup_current = current;
    //left
    if(left(board,current)) {
        solve(board,current,depth-1);
        board = backup;
        current = backup_current;
    }

    //right
    if(right(board,current)) {
        solve(board,current,depth-1);
        board = backup;
        current = backup_current;
    }

    //up
    if(up(board,current)) {
        solve(board,current,depth-1);
        board = backup;
        current = backup_current;
    }

    //down
    if(down(board,current)) {
        solve(board,current,depth-1);
        //board = backup;
        //current = backup_current;
    }
}

int main() {
    cin >> N;
    cin.tie(NULL);
    vector<vector<int>> board(N,vector<int>(N));
    int cur = 0;
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < N;j++) {
            cin >> board[i][j];
            cur = max(cur,board[i][j]);
        }
    }
    if(N == 1) {
        cout << board[0][0];
        return 0;
    }
    answer = cur;
    solve(board,cur,10);
    cout << answer;
    return 0;
}