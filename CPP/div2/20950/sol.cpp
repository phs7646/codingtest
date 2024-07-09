#include<iostream>
#include<vector>
using namespace std;

int N;
vector<vector<int>> colors(30,vector<int>(3));
vector<int> target(3);
vector<int> cur(3);
int num_use;
int record = 255*3;


int diff() {
    int sum = 0;
    for(int i = 0;i < 3;i++) {
        sum += abs(target[i]-cur[i]/num_use);
    }
    return sum;
}

void dfs(int start) {
    if(start == N) {
        if(num_use >= 2) {
            int d = diff();
            if(d < record) record = d;
        }
        return;
    }
    //use
    if(num_use < 7) {
        num_use++;
        for(int i = 0;i < 3;i++) {
            cur[i] += colors[start][i];
        }
        dfs(start+1);
        for(int i = 0;i < 3;i++) {
            cur[i] -= colors[start][i];
        }
        num_use--;
    }
    //not use
    dfs(start+1);
    
}

int main() {
    cin >> N;
    for(int n = 0;n < N;n++) cin >> colors[n][0] >> colors[n][1] >> colors[n][2];
    cin >> target[0] >> target[1] >> target[2];
    dfs(0);
    cout << record;
    return 0;
}