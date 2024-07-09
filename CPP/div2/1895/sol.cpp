#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int R,C;
    cin >> R >> C;
    vector<vector<int>> board(R,vector<int>(C));
    for(int i = 0;i < R;i++) for(int j = 0;j < C;j++) cin >> board[i][j];
    int T;
    cin >> T;
    int count = 0;
    for(int i = 0;i < R-2;i++) {
        for(int j = 0;j < C-2;j++) {
            vector<int> tmp;
            for(int a = i;a < i+3;a++) for(int b = j;b < j+3;b++) tmp.push_back(board[a][b]);
            sort(tmp.begin(),tmp.end());
            if(tmp[4] >= T) count++;
        }
    }
    cout << count;
    return 0;
}