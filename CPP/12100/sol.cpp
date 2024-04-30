#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/* helper functions */

template<typename T>
void vectorprint(vector<T>& v) {
    for(T t : v) cout << t << " ";
    cout << "\n";
}

template<typename T>
vector<T> vectorinput(int n) {
    vector<T> ret(n);
    for(int i = 0;i < n;i++) cin >> ret[i];
    return ret;
}

/* codes */
int N;

vector<int> update(vector<int>& v, int& flag) { //0 : nothing changed, 1 : something changed
    vector<int> ret(N);
    //if something, return true. else false
    flag = 0;
    int pos = 0;
    for(int index = 0;index < N;index++) {
        if(v[index] == 0) continue;
        int index2 = index+1;
        while(index2 < N && v[index2] == 0) index2++;
        if(index2 < N && v[index] == v[index2]) {
            ret[pos] = v[index] * 2;
            pos++;
            index = index2;
        } else {
            ret[pos] = v[index];
            pos++;
        }
    }
    for(int i = 0;i < N;i++) {
        if(v[i] != ret[i]) {
            flag = 1;
            break;
        }
    }
    return ret;
}

int left(vector<vector<int>>& board) { //0 : nothing changed, 1 : something changed
    int final_flag = 0;
    for(int i = 0;i < N;i++) {
        int flag;
        board[i] = update(board[i],flag);
        final_flag = max(flag,final_flag);
    }
    return final_flag;
}
int right(vector<vector<int>>& board) {
    int final_flag = 0;
    for(int i = 0;i < N;i++) {
        int flag;
        reverse(board[i].begin(),board[i].end());
        board[i] = update(board[i],flag);
        reverse(board[i].begin(),board[i].end());
        final_flag = max(flag,final_flag);
    }
    return final_flag;
}
int up(vector<vector<int>>& board) {
    int final_flag = 0;
    for(int i = 0;i < N;i++) {
        vector<int> v(N);
        for(int j = 0;j < N;j++) v[j] = board[j][i];
        int flag;
        v = update(v,flag);
        for(int j = 0;j < N;j++) board[j][i] = v[j];
        final_flag = max(flag,final_flag);
    }
    return final_flag;
}
int down(vector<vector<int>>& board) {
    int final_flag = 0;
    for(int i = 0;i < N;i++) {
        vector<int> v(N);
        for(int j = 0;j < N;j++) v[j] = board[N-j-1][i];
        int flag;
        v = update(v,flag);
        for(int j = 0;j < N;j++) board[N-j-1][i] = v[j];
        final_flag = max(flag,final_flag);
    }
    return final_flag;  
}

void myprint(vector<vector<int>> v) {
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < N;j++) {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
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

    //left
    vector<vector<int>> board_left = board;
    int flag = left(board_left);
    if(flag == 1) solve(board_left,depth-1);

    //right
    vector<vector<int>> board_right = board;
    flag = right(board_right);
    if(flag == 1) solve(board_right,depth-1);

    //up
    vector<vector<int>> board_up = board;
    flag = up(board_up);
    if(flag == 1) solve(board_up,depth-1);

    //down
    vector<vector<int>> board_down = board;
    flag = down(board_down);
    if(flag == 1) solve(board_down,depth-1);
}

int main() {
    cin >> N;
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
    solve(board,5);
    cout << answer;
    return 0;
}