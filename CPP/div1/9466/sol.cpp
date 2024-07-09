#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int test = 0; test < T;test++) {
        int N;
        cin >> N;
        vector<int> v(N+1);
        int answer = 0;

        for(int i = 1;i <= N;i++) {
            cin>>v[i];
        }

        vector<bool> alive(N+1,true);

        for(int i = 1;i <= N;i++) {
            if(!alive[i]) continue;
            vector<int> history;
            history.push_back(i);
            alive[i] = false;
            while(true) {
                int next = v[history.back()];
                history.push_back(next);
                if(!alive[next]) break;
                alive[next] = false;
            }
            //for(int h : history) cout << h << " ";
            //cout << "\n";
            auto it = find(history.begin(),history.end(),history.back());
            //cout << "add " <<  (history.end() - it - 1) << "\n";
            answer += (history.end() - it - 1);
        }

        cout << N-answer << "\n";
    }

    return 0;
}