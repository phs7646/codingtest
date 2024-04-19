#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct wood {
    int x,y,cost;
} wood;

int main() {
    int N;
    cin >> N;
    vector<wood> v;
    for(int i = 0;i < N;i++) {
        wood w;
        cin >> w.x >> w.y >> w.cost;
        v.push_back(w);
    }
    queue<vector<int>> q;
    q.push(vector<int>(0));

    while(!q.empty()) {
        vector<int> used = q.front();
        q.pop();

        vector<int> alive(N,1);
        for(int n : used) alive[n] = 0;

        int min_x_id = -1;
        int max_x_id = -1;
        int min_y_id = -1;
        int max_y_id = -1;
        int cost_max_id = -1;
        int have = 0;
        int num_zero = 0;

        //find values
        for(int i = 0;i < N;i++) {
            if(alive[i] == 1) {
                if(min_x_id == -1) {
                    min_x_id = i;
                    max_x_id = i;
                    min_y_id = i;
                    max_y_id = i;
                    cost_max_id = i;
                    continue;
                }
                if(v[min_x_id].x > v[i].x) min_x_id = i;
                if(v[max_x_id].x < v[i].x) max_x_id = i;
                if(v[min_y_id].y > v[i].y) min_y_id = i;
                if(v[max_y_id].y < v[i].y) max_y_id = i;
                if(v[cost_max_id].cost < v[i].cost) cost_max_id = i;
                
            } else {
                num_zero++;
                have += v[i].cost;
            }
        }


        //check if available
        int distx = v[max_x_id].x - v[min_x_id].x;
        int disty = v[max_y_id].y - v[min_y_id].y;
        int need = (distx + disty) * 2;
        /*
        cout << "[Case] ";
        for(int i : used) cout << " " << i;
        cout << "\n";
        cout << "need : " << need << ", have : " << have << "\n";
        */
        if(need <= have) {
            cout << num_zero;
            return 0;
        }

        //push q
        vector<int> v1;
        for(int n : used) v1.push_back(n);
        v1.push_back(min_x_id);
        q.push(v1);

        if(max_x_id != min_x_id) {
            vector<int> v2;
            for(int n : used) v2.push_back(n);
            v2.push_back(max_x_id);
            q.push(v2);
        }

        if(min_y_id != min_x_id && min_y_id != max_x_id) {
            vector<int> v3;
            for(int n : used) v3.push_back(n);
            v3.push_back(min_y_id);
            q.push(v3);
        }

        if(max_y_id != min_x_id && max_y_id != max_x_id && max_y_id != min_y_id) {
            vector<int> v4;
            for(int n : used) v4.push_back(n);
            v4.push_back(min_y_id);
            q.push(v4);
        }

        if(cost_max_id != min_x_id && cost_max_id != max_x_id && cost_max_id != min_y_id && cost_max_id != max_y_id) {
            vector<int> v5;
            for(int n : used) v5.push_back(n);
            v5.push_back(cost_max_id);
            q.push(v5);
        }
    }
    return 0;
}