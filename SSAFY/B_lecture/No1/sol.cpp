#include<iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int answerbit = (1<<10)-1;
    int T; cin >> T;
    for(int t = 1;t <= T;t++) {
        int N; cin >> N;
        int bit = 0;
        int answer = 1;
        int cur = N;
        while(true) {
            //count
            int _cur = cur;
            while(_cur > 0) {
                bit |= (1<<(_cur%10));
                _cur /= 10;
            }
            //check
            if(bit == answerbit) break;

            //progress
            cur += N;
            answer++;
        }
        cout << '#' << t << ' ' << answer*N << '\n';
    }

}