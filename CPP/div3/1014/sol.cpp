#include<iostream>
#include<algorithm>

using namespace std;
#define debug 0

char map[10][10];
int candidates[1<<10];
int dp[10][1<<10]; //dp

bool isAvailable(int M,int bit1,int bit2) {
    //bit1 다음에 bit2 가 올 수 있는지?
    bool arr[10] = {false};
    for(int index = 0;index < M;index++) {
        if(bit1 & 1) arr[index] = true;
        bit1 >>= 1;
    }
    for(int index = 0;index < M;index++) {
        if(bit2 & 1) {
            //왼쪽뒤, 오른쪽뒤에 사람있으면 안됨
            if(index != 0 && arr[index-1]) return false;
            if(index < M-1 && arr[index+1]) return false;
        }
        bit2 >>= 1;
    }
    return true;
}
int main() {
    int T; cin >> T;
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    for(int t = 0;t < T;t++) {
        if(debug) cout << "Test case #" << t << "\n";
        int N,M; cin >> N >> M;
        for(int i = 0;i < N;i++) for(int j = 0;j < M;j++) cin >> map[i][j];
        int answer = 0;
        int max_bit = 1<<M;
        //create candidates for M
        int num_cand = 0;
        if(debug) cout << "cand : ";
        for(int bit = 0;bit < max_bit;bit++) {
            //not continous 1
            int _bit = bit;
            int prev = _bit & 1;
            _bit >>= 1;
            bool flag = true;
            while(_bit > 0) {
                int cur = _bit & 1;
                if(cur == 1 && prev == 1) {
                    flag = false;
                    break;
                }
                prev = cur;
                _bit >>= 1;
            }
            if(flag) {
                candidates[num_cand++] = bit;
                if(debug) cout << bit << " ";
            }
        }
        if(debug) cout << endl;
        //initial row N-1
        if(debug) cout << "row " << N-1 << " : " ;
        fill(dp[N-1],dp[N-1]+max_bit,0);
        for(int i = 0;i < num_cand;i++) {
            int bit = candidates[i];
            //is bit possible?
            bool flag = true;
            int selected = 0;
            int _bit = bit;
            for(int index = 0;index < M;index++) {
                if((_bit & 1)) {
                    selected++;
                    if(map[N-1][index] == 'x') {
                        flag = false;
                        break;
                    }
                }
                _bit >>= 1;
            }
            if(flag) {
                dp[N-1][bit] = selected;
                answer = max(answer,selected);
            }
            if(debug) {
                cout << dp[N-1][bit] << " ";
            }
        }
        if(debug) cout << endl;
        //dp run
        for(int i = N-2;i >= 0;i--) {
            if(debug) cout << "row " << i << " : ";
            fill(dp[i],dp[i]+max_bit,0);
            //i th row
            for(int bit_index = 0;bit_index < num_cand;bit_index++) {
                int bit = candidates[bit_index];
                //check if available in current line
                int cur_selected = 0;
                bool flag = true;
                int _bit = bit;
                for(int index = 0;index < M;index++) {
                    if(_bit & 1) {
                        cur_selected++;
                        if(map[i][index] == 'x') {
                            flag = false;
                            break;
                        }
                    }
                    _bit >>= 1;
                }
                if(!flag) {
                    if(debug) cout << "0 ";
                    continue; //not availale
                }
                //find maximum prev row
                int prev_max = 0;
                for(int prev_cand_index = 0;prev_cand_index < num_cand;prev_cand_index++) {
                    int prev_bit = candidates[prev_cand_index];
                    if(dp[i+1][prev_bit] == 0) continue;
                    if(isAvailable(M,prev_bit,bit)) {
                        prev_max = max(prev_max,dp[i+1][prev_bit]);
                    }
                }
                dp[i][bit] = prev_max + cur_selected;
                if(debug) cout << dp[i][bit] << " ";
                answer = max(answer,dp[i][bit]);
            }
            if(debug) cout << "\n";
        }
        cout << answer << "\n";
    }
    return 0;
}