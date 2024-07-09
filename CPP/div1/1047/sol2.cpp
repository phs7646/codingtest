#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

typedef struct wood {
    int x,y,cost;
} wood;

int main() {
    int N;
    cin >> N;
    vector<wood> woods;
    for(int i = 0;i < N;i++) {
        wood w;
        cin >> w.x >> w.y >> w.cost;
        woods.push_back(w);
    }

    unordered_map<long long,bool> memo;

    queue<long long> q;
    memo[0] = true;
    q.push(0);

    while(!q.empty()) {
        long long used = q.front();
        q.pop();

        int min_x_id = -1;
        int max_x_id = -1;
        int min_y_id = -1;
        int max_y_id = -1;
        int cost_max_id = -1;
        int have = 0;
        int num_zero = 0;

        //find values
        for(int i = 0;i < N;i++) {
            if(((used >> i) & 1) == 0) { //alive
                if(min_x_id == -1) {
                    min_x_id = i;
                    max_x_id = i;
                    min_y_id = i;
                    max_y_id = i;
                    cost_max_id = i;
                    continue;
                }
                if(woods[min_x_id].x > woods[i].x) min_x_id = i;
                if(woods[max_x_id].x < woods[i].x) max_x_id = i;
                if(woods[min_y_id].y > woods[i].y) min_y_id = i;
                if(woods[max_y_id].y < woods[i].y) max_y_id = i;
                if(woods[cost_max_id].cost < woods[i].cost) cost_max_id = i;
                
            } else {
                num_zero++;
                have += woods[i].cost;
            }
        }


        //check if available
        int distx = woods[max_x_id].x - woods[min_x_id].x;
        int disty = woods[max_y_id].y - woods[min_y_id].y;
        int need = (distx + disty) * 2;
        
        //cout << "[Case] " << used << "\n";
        //cout << "need : " << need << ", have : " << have << "\n";
        
        if(need <= have) {
            cout << num_zero;
            return 0;
        }

        //push q
        vector<int> cand = {min_x_id,max_x_id,min_y_id,max_y_id,cost_max_id};
        for(int victim : cand) {
            long long newused = used + (1LL << victim);
            if(memo.find(newused) == memo.end()) {
                memo[newused] = true;
                q.push(newused);
            }
        }
    }
    return 0;
}