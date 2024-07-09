#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> board(N);
    vector<vector<bool>> visited(N,vector<bool>(N));

    for(int i = 0;i < N;i++) {
        cin >> board[i];
    }
    for(int i = 0;i < N;i++) {
        string s;
        cin >> s;
        for(int j = 0;j < N;j++) {
            if(s[j] == 'x') visited[i][j] = true;
            else visited[i][j] = false;
        }
    }
    bool mineclikced = false;
    
    vector<vector<char>> ret(N,vector<char>(N,'.'));
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < N;j++) {
            if(visited[i][j]) {
                if(board[i][j] == '*') {
                    mineclikced = true;
                    continue;
                }
                int count = 0;
                for(int a = i-1;a <= i+1;a++) {
                    for(int b = j-1;b <= j+1;b++) {
                        if(0<=a && a<N && 0<=b && b<N && board[a][b] == '*') count++; 
                    }
                }
                ret[i][j] = '0' + count;
            }
        }
    }
    if(mineclikced) {
        for(int i = 0;i < N;i++) {
            for(int j = 0;j < N;j++) {
                if(board[i][j] == '*') ret[i][j] = '*';
            }
        }
    }
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < N;j++) {
            cout<<ret[i][j];
        }
        cout << endl;
    }
    
    return 0;
}