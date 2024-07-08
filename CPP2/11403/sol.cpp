#include<iostream>
#include<vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> adj(N,vector<int>(N));
    for(int i = 0;i < N;i++) for(int j = 0;j < N;j++) cin >> adj[i][j];
    for(int k = 0;k < N;k++) {
        for(int i = 0;i < N;i++) {
            for(int j = 0;j < N;j++) {
                if(adj[i][j]) continue;
                if(adj[i][k] == 1 && adj[k][j] == 1) adj[i][j] = 1;
            }
        }
    }
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < N;j++) cout << adj[i][j] << " ";
        cout << endl;
    }
    return 0;
}