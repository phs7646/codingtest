#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

#define MAXN 100000
#define debug 0

long long h[MAXN];
int stackLeft[MAXN];
int stackRight[MAXN];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int N;
    while(true) {
        cin >> N;
        if(N == 0) break;
        for(int i = 0;i < N;i++) cin >> h[i];
        
        priority_queue<pair<int,int>> pq;

        //build left : 왼쪽에 나보다 큰 녀석이 몇개나 있는지
        for(int i = N-1;i >= 0;i--) {
            //현재 h[i] 보다 큰 녀석들은 모두 죽는다
            while(!pq.empty()) {
                if(pq.top().first > h[i]) {
                    int idx = pq.top().second;
                    stackLeft[idx] = idx-i-1;
                    pq.pop();
                } else break;
            }
            //i를 pq에 넣는다
            pq.emplace(h[i],i);
        }
        //pq에 살아있는 애들 처리
        while(!pq.empty()) {
            int idx = pq.top().second;
            stackLeft[idx] = idx;
            pq.pop();
        }
        if(debug) {
            cout << "Printing left... ";
            for(int i = 0;i < N;i++) cout << stackLeft[i] << " ";
            cout << endl;
        }


        //build right : 오른쪽에 나보다 큰 녀석이 몇개나 있는지
        for(int i = 0;i < N;i++) {
            //현재 h[i] 보다 큰 녀석들은 모두 죽는다
            while(!pq.empty()) {
                if(pq.top().first > h[i]) {
                    int idx = pq.top().second;
                    stackRight[idx] = abs(i-idx-1);
                    pq.pop();
                } else break;
            }
            //i를 pq에 넣는다
            pq.emplace(h[i],i);
        }
        //pq에 살아있는 애들 처리
        while(!pq.empty()) {
            int idx = pq.top().second;
            stackRight[idx] = abs(N-idx-1);
            pq.pop();
        }
        if(debug) {
            cout << "Printing right... ";
            for(int i = 0;i < N;i++) cout << stackRight[i] << " ";
            cout << endl;
        }

        //calculate area
        long long answer = 0;
        for(int i = 0;i < N;i++) {
            answer = max(answer,h[i] * (stackLeft[i] + 1 + stackRight[i]));
        }
        cout << answer << "\n";
    }
    return 0;
}