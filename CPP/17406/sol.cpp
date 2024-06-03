#include<iostream>
#include<vector>
#include<climits>

using namespace std;
int N,M,K;
vector<vector<int>> rotates(6,vector<int>(3));

void arrayprint(vector<vector<int>>& A) {
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < M;j++) cout << A[i][j] << " ";
        cout << endl;
    }
}

vector<vector<int>> rotate(const vector<vector<int>>& origin, vector<int> params) {
    vector<vector<int>> ret = origin;
    int r = params[0]-1;
    int c = params[1]-1;
    int s = params[2];
    for(int layer = 1;layer <= s;layer++) {
        int y = r-layer;
        int x = c-layer;
        int amount = layer<<1;
        for(int i = 0;i < amount;i++) {ret[y][x+1] = origin[y][x]; x++;} //go right
        for(int i = 0;i < amount;i++) {ret[y+1][x] = origin[y][x]; y++;} //go down
        for(int i = 0;i < amount;i++) {ret[y][x-1] = origin[y][x]; x--;} //go left
        for(int i = 0;i < amount;i++) {ret[y-1][x] = origin[y][x]; y--;} //go up
    }
    return ret;
}

int value(const vector<vector<int>>& A) {
    int ret = INT_MAX;
    for(int i = 0;i < N;i++) {
        int sum = 0;
        for(int j = 0;j < M;j++) sum += A[i][j];
        ret = min(ret,sum);
    }
    return ret;
}

vector<bool> used;

int dfs(const vector<vector<int>>& A) {
    bool flag = true;
    for(int i = 0;i < K;i++) {
        if(used[i] == false) {
            flag = false;
            break;
        }
    }
    if(flag) {
        //end of calculation
        return value(A);
    }

    int ret = INT_MAX;
    for(int k = 0;k < K;k++) {
        if(used[k]) continue;
        vector<vector<int>> new_A = rotate(A,rotates[k]);
        used[k] = true;
        ret = min(ret,dfs(new_A));
        used[k] = false;
    }
    return ret;
}

int main() {
    cin >> N >> M >> K;
    vector<vector<int>> A(N,vector<int>(M));
    for(int i = 0;i < N;i++) for(int j = 0;j < M;j++) cin >> A[i][j];
    
    for(int k = 0;k < K;k++) cin >> rotates[k][0] >> rotates[k][1] >> rotates[k][2];

    used.resize(K);
    cout << dfs(A);

    return 0;   
}