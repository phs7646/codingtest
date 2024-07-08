#include<iostream>
#include<vector>

using namespace std;
int N,M;

vector<vector<int>> func1(vector<vector<int>>& v) {
    vector<vector<int>> ret(N,vector<int>(M));
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < M;j++) {
            ret[i][j] = v[N-i-1][j];
        }
    }
    return ret;
}
vector<vector<int>> func2(vector<vector<int>>& v) {
    vector<vector<int>> ret(N,vector<int>(M));
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < M;j++) {
            ret[i][j] = v[i][M-1-j];
        }
    }
    return ret;
}

vector<vector<int>> func3(vector<vector<int>>& v) {
    vector<vector<int>> ret(M,vector<int>(N));
    for(int i = 0;i < M;i++) {
        for(int j = 0;j < N;j++) {
            //0,1 -> N-2,0
            ret[i][j] = v[N-j-1][i];
        }
    }
    int t = M;
    M = N;
    N = t;
    return ret;
}
vector<vector<int>> func4(vector<vector<int>>& v) {
    vector<vector<int>> ret(M,vector<int>(N));
    for(int i = 0;i < M;i++) {
        for(int j = 0;j < N;j++) {
            //0,1 -> 1,M-1
            ret[i][j] = v[j][M-1-i];
        }
    }
    int t = M;
    M = N;
    N = t;
    return ret;
}

vector<vector<int>> func5(vector<vector<int>>& v) {
    vector<vector<int>> ret(N,vector<int>(M));
    int hN = N/2;
    int hM = M/2; 
    for(int i = 0;i < hN;i++) {
        for(int j = 0;j < hM;j++) {
            ret[i][j] = v[i+hN][j];
            ret[i][j+hM] = v[i][j];
            ret[i+hN][j] = v[i+hN][j+hM];
            ret[i+hN][j+hM] = v[i][j+hM];
        }
    }
    return ret;
}
vector<vector<int>> func6(vector<vector<int>>& v) {
    vector<vector<int>> ret(N,vector<int>(M));
    int hN = N/2;
    int hM = M/2; 
    for(int i = 0;i < hN;i++) {
        for(int j = 0;j < hM;j++) {
            ret[i][j] = v[i][j+hM];
            ret[i][j+hM] = v[i+hN][j+hM];
            ret[i+hN][j] = v[i][j];
            ret[i+hN][j+hM] = v[i+hN][j];
        }
    }
    return ret;
}


int main() {
    int R;
    cin >> N >> M >> R;
    vector<vector<int>> board(N,vector<int>(M));
    for(int i = 0;i < N;i++) for(int j = 0;j < M;j++) cin >> board[i][j];
    for(int r = 0;r < R;r++) {
        int num;
        cin >> num;
        if(num == 1) board = func1(board);
        else if(num == 2) board = func2(board);
        else if(num == 3) board = func3(board);
        else if(num == 4) board = func4(board);
        else if(num == 5) board = func5(board);
        else if(num == 6) board = func6(board);
    }
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < M;j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}