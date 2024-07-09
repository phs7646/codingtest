#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main() {
    int N,K;
    cin >> N >> K;
    vector<vector<int>> dist(N,vector<int>(N,2*N));
    for(int i = 0;i < K;i++) {
        int a,b;
        cin >> a >> b;
        dist[a-1][b-1] = 1;
        dist[b-1][a-1] = 1;
    }
    for(int i = 0;i < N;i++) dist[i][i] = 0;


    for(int k = 0;k < N;k++) {
        for(int i = 0;i < N;i++) {
            for(int j = 0;j < N;j++) {
                if(dist[i][k] < 2*N && dist[k][j] < 2*N)
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }


    
    bool flag = true;
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < N;j++) {
            //cout << dist[i][j] << " ";
            if(dist[i][j] > 6) {
                flag = false;
                break;
            }
        }
        //cout << endl;
    }
        

    if(flag) {
        cout << "Small World!";
    } else {
        cout << "Big World!";
    }
    return 0;
}