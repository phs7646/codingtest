#include <iostream>
#include <queue>
#include <vector>
using namespace std;


typedef struct room {
    char type;
    int cost;
    vector<int> next;
} room;

room r[1000];
int C[1000]; //C[i] is maximum coins after i
int main() {
    while(1) {
        int N;
        cin >> N;
        if(N==0) break;
        for(int i = 0;i < N;i++) {
            cin >> r[i].type >> r[i].cost;
            r[i].next.clear();
            while(1) {
                int n;
                cin >> n;
                if(n == 0) break;
                n--;
                r[i].next.push_back(n);
                C[i] = -1;
            }
        }
        queue<int> q;
        
        int current = 0;
        if(r[0].type == 'T') {
            cout << "No\n";
            continue;
        } else if(r[0].type == 'L') {
            current = r[0].cost;
        }
        C[0] = current;
        q.push(0);

        bool flag = false;
        while(!q.empty()) {
            int t = q.front();
            q.pop();
            //C[t]
            int coin = C[t];
            for(int next : r[t].next) {
                if(r[next].type == 'T' && coin < r[next].cost) continue;
                if(next == N-1) {
                    flag = true;
                    break;
                }
                int next_coin = coin;
                if(r[next].type == 'L' && r[next].cost > coin) next_coin = r[next].cost;
                else if(r[next].type == 'T') next_coin -= r[next].cost;
                if(C[next] == -1 || C[next] < next_coin) {
                    C[next] = next_coin;
                    q.push(next);
                } 
            }
            if(flag) break;
        }
        if(flag) {
            cout<<"Yes\n";
        } else {
            cout<<"No\n";
        }

    }
}