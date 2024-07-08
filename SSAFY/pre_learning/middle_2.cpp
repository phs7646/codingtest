#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> rotate(int N,vector<vector<int>>& board) {
    vector<vector<int>> ret(N,vector<int>(N));
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < N;j++) {
            ret[j][N-i-1] = board[i][j]; 
        }
    }
    return ret;
}

int main(int argc, char** argv)
{
	int T;
    cin >> T;
    for(int t = 0;t < T;t++) {
        int N;
        cin >> N;
        vector<vector<int>> board(N,vector<int>(N));
        for(int i = 0;i < N;i++) for(int j = 0;j < N;j++) cin >> board[i][j];
        vector<vector<int>> v1 = rotate(N,board);
        vector<vector<int>> v2 = rotate(N,v1);
        vector<vector<int>> v3 = rotate(N,v2);

        cout << "#" << t+1 << "\n";
        for(int i = 0;i < N;i++) {
            for(int j = 0;j < N;j++) cout << v1[i][j];
            cout << " ";
            for(int j = 0;j < N;j++) cout << v2[i][j];
            cout << " ";
            for(int j = 0;j < N;j++) cout << v3[i][j];
            cout << "\n";
        }
    }
	return 0;
}