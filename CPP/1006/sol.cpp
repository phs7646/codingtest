#include<iostream>
#include<vector>
#include<climits>

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
int N,W;
int solve(vector<int>& v1,vector<int>& v2) {
    vector<vector<int>> dp(N,vector<int>(3,INT_MAX)); // [i][0] : v1 [i][1] : v2 [i][2] : 둘다
    dp[0][0] = 1;
    dp[0][1] = 1;
    dp[0][2] = v1.front() + v2.front() <= W ? 1 : 2;

    for(int i = 1;i < N;i++) {
        dp[i][0] = dp[i-1][2] + 1;
        if(v1[i-1] + v1[i] <= W) dp[i][0] = min(dp[i][0],dp[i-1][1] + 1);
        dp[i][1] = dp[i-1][2] + 1;
        if(v2[i-1] + v2[i] <= W) dp[i][1] = min(dp[i][1],dp[i-1][0] + 1);
        dp[i][2] = min(dp[i][0],dp[i][1]) + 1;
        if(v1[i] + v2[i] <= W) dp[i][2] = min(dp[i][2],dp[i-1][2] + 1);
        if(v1[i-1] + v1[i] <= W && v2[i-1] + v2[i] <= W) {
            if(i == 1) dp[i][2] = min(dp[i][2],2);
            else dp[i][2] = min(dp[i][2],dp[i-2][2]+2);
        }
    }
    /*
    for(int i = 0;i < N;i++) {
        cout << dp[i][0] << " , " << dp[i][1] << " , " << dp[i][2] << "\n";
    }
    */
    return dp[N-1][2];
}

int main() {
    int T;
    cin >> T;
    for(int t = 0;t < T;t++) {
        cin >> N >> W;
        vector<int> v1 = vectorinput<int>(N);
        vector<int> v2 = vectorinput<int>(N);
        if(N == 1) {
            if(v1[0] + v2[0] <= W) cout << 1 << "\n";
            else cout << 2 << "\n";
            continue;
        }
        bool case_0 = v1.front() + v1.back() <= W;
        bool case_1 = v2.front() + v2.back() <= W;
        int answer = INT_MAX;
        
        
        // case 1 : no connection between N-1, 0
        int val1 = solve(v1,v2);
        answer = min(answer,val1);
        //cout << "Case 1 : " << val1 << "\n";

        // case 2 : case 0
        if(case_0) {
            int backup_1 = v1[0];
            int backup_2 = v1[N-1];
            v1[0] = W;
            v1[N-1] = W;
            int val2 = solve(v1,v2);
            //cout << "Case 2 : " << val2-1 << "\n";
            answer = min(answer,val2-1);
            v1[0] = backup_1;
            v1[N-1] = backup_2;
        }

        //case 3 : case 1
        if(case_1) {
            int backup_1 = v2[0];
            int backup_2 = v2[N-1];
            v2[0] = W;
            v2[N-1] = W;
            int val3 = solve(v1,v2);
            //cout << "Case 3 : " << val3-1 << "\n";
            answer = min(answer,val3-1);
            v2[0] = backup_1;
            v2[N-1] = backup_2;
        }

        //case 4 : both
        if(case_0 && case_1) {
            v1[0] = W;
            v1[N-1] = W;
            v2[0] = W;
            v2[N-1] = W;
            int val4 = solve(v1,v2);
            //cout << "Case 4 : " << val4-2 << "\n";
            answer = min(answer,val4-2);
        }
        cout << answer << "\n";
    }
    return 0;
}