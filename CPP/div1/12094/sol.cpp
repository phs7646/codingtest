#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//벡터 복사를 줄여보자.. update함수내에서 tmp를 만들지말고 기존 벡터에서 바로 진행?
//left right 완료, up down도 ret없이 가능할듯.
//방향 함수에서 변화 여부를 미리 감지하자 (만약 첫번째 라인에서 변화가 있었따면 이후에는 변화감지 x)
/* helper functions */

template<typename T>
vector<T> vectorinput(int n) {
    vector<T> ret(n);
    for(int i = 0;i < n;i++) cin >> ret[i];
    return ret;
}

/* codes */
int N;

bool update_left(vector<int>& v) {
    bool ret = false;
    vector<int> tmp;
    bool flag = false;
    for(int n : v) {
        if(n != 0) {
            tmp.push_back(n);
            if(flag) ret = true; //skipped
        } else {
            flag = true;
        }
    }
    int pos = 0;
    int tsize = tmp.size();
    for(int i = 0;i < tsize;i++) {
        if(i+1 < tsize && tmp[i] == tmp[i+1]) {
            v[pos] = tmp[i]<<1;
            pos++;
            i++;
            ret = true;
        } else {
            v[pos] = tmp[i];
            pos++;
        }
    }
    for(;pos < N;pos++) v[pos] = 0;
    return ret;
}

bool update_right(vector<int>& v) {
    bool ret = false;
    vector<int> tmp;
    bool flag = false;
    for(int i = N-1;i >= 0;i--) {
        if(v[i] != 0) {
            tmp.push_back(v[i]);
            if(flag) ret = true;
        } else {
            flag = true;
        }
    }
    int pos = N-1;
    int tsize = tmp.size();
    for(int i = 0;i < tsize;i++) {
        if(i+1 < tsize && tmp[i] == tmp[i+1]) {
            v[pos] = tmp[i] << 1;
            pos--;
            i++;
            ret = true;
        } else {
            v[pos] = tmp[i];
            pos--;
        }
    }
    for(;pos >= 0;pos--) v[pos] = 0;
    return ret;
}

bool left(vector<vector<int>>& board) {
    bool ret = false;
    for(int i = 0;i < N;i++) {
        ret = update_left(board[i]);
    }
    return ret;
}
bool right(vector<vector<int>>& board) {
    bool ret = false;
    for(int i = 0;i < N;i++) {
        ret = update_right(board[i]);
    }
    return ret;
}
bool up(vector<vector<int>>& board) {
    bool ret = false;
    for(int i = 0;i < N;i++) {
        vector<int> tmp;
        bool flag = false;
        for(int j = 0;j < N;j++)  {
            if(board[j][i] != 0) {
                tmp.push_back(board[j][i]);
                if(flag) ret = true;
            } else flag = true;
        }
        int pos = 0;
        int tsize = tmp.size();
        for(int j = 0;j < tsize;j++) {
            if(j+1 < tsize && tmp[j] == tmp[j+1]) {
                board[pos][i] = tmp[j] << 1;
                pos++;
                j++;
                ret = true;
            } else {
                board[pos][i] = tmp[j];
                pos++;
            }
        }
        for(;pos < N;pos++) board[pos][i] = 0;
    }
    return ret;
}
bool down(vector<vector<int>>& board) {
    bool ret = false;
    for(int i = 0;i < N;i++) {
        vector<int> tmp;
        bool flag = false;

        for(int j = N-1;j >= 0;j--) {
            if(board[j][i] != 0) {
                tmp.push_back(board[j][i]);
                if(flag) ret = true;
            } else flag = true;
        }
        int pos = N-1;
        int tsize = tmp.size();
        for(int j = 0;j < tsize;j++) {
            if(j+1 < tsize && tmp[j] == tmp[j+1]) {
                board[pos][i] = tmp[j]<<1;
                pos--;
                j++;
                ret = true;
            } else {
                board[pos][i] = tmp[j];
                pos--;
            }
        }
        for(;pos >= 0;pos--) board[pos][i] = 0;
    }
    return ret;
}

int answer = 0;

int maxvalue(const vector<vector<int>>& board) {
    int ret = board[0][0];
    for(int i = 0;i < N;i++) {
        ret = max(ret,*max_element(board[i].begin(),board[i].end()));
    }
    return ret;
}

void solve(vector<vector<int>>& board, int depth) {
    int current = maxvalue(board);
    answer = max(answer,current);
    if(depth == 0) return;
    int possible_maximum = (current << depth);
    if(answer >= possible_maximum) return;

    vector<vector<int>> backup = board;
    //left
    if(left(board)) {
        solve(board,depth-1);
        board = backup;
    }

    //right
    if(right(board)) {
        solve(board,depth-1);
        board = backup;
    }

    //up
    if(up(board)) {
        solve(board,depth-1);
        board = backup;
    }

    //down
    if(down(board)) {
        solve(board,depth-1);
        board = backup;
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
    solve(board,10);
    cout << answer;
    return 0;
}