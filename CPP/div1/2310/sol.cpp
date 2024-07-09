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
int C[1000]; //C[i] is maximum coins before enter i
int main() {
    while(1) {
        int N;
        bool flag = false;
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
        q.push(0);

        while(!q.empty()) {
            int t = q.front();
            q.pop();
            if(r[t].type == 'T' && r[t].cost > C[t]) continue; //can't enter
            if(t == N-1) {
                cout << "YES\n";
                flag = true;
                break;
            }
            int current = C[t];
            if(r[t].type == 'L' && r[t].cost > C[t]) current = r[t].cost; //get money

            for(int next : r[t].next) {
                C[next] = current;
                q.push(next);
            }
        }
        if(!flag) {
            cout << "No\n";
        }

    }
}