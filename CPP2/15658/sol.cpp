#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int N;
vector<int> v(11);
vector<int> op(4);
vector<int> used(4);
vector<int> history;

int answerMax = INT_MIN;
int answerMin = INT_MAX;

void dfs() {
    if(history.size() == N-1) {
        //evaluate
        int value = v[0];
        for(int i = 0;i < N-1;i++) {
            if(history[i] == 0) value += v[i+1];
            else if(history[i] == 1) value -= v[i+1];
            else if(history[i] == 2) value *= v[i+1];
            else {
                if(value < 0) {
                    value = -(-value / v[i+1]);
                } else {
                    value /= v[i+1];
                }
            }
        }
        answerMax = max(answerMax,value);
        answerMin = min(answerMin,value);
        return;
    }
    for(int i = 0;i < 4;i++) {
        if(used[i] < op[i]) {
            history.push_back(i);
            used[i]++;
            dfs();
            used[i]--;
            history.pop_back();
        }
    }
}

int main() {

    cin >> N;
    for(int i = 0;i < N;i++) cin >> v[i];
    for(int i = 0;i < 4;i++) cin >> op[i];
    dfs();
    cout << answerMax << endl;
    cout << answerMin;
    return 0;
}