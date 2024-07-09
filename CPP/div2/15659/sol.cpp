#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int N;
vector<int> A(11);
vector<int> ops(4);
vector<int> used(4);
vector<int> history;
int answer_max = INT_MIN;
int answer_min = INT_MAX;
int calculate() {
    vector<int> values;
    vector<int> operators;
    //calculate * and / first
    for(int op_pos = 0;op_pos <= history.size();op_pos++) {
        if(history[op_pos] == 0 || history[op_pos] == 1) {
            values.push_back(A[op_pos]);
            if(op_pos < history.size()) operators.push_back(history[op_pos]);
        } else {
            int value = A[op_pos];
            while(op_pos < history.size() && history[op_pos] >= 2) {
                if(history[op_pos] == 2) value *= A[op_pos+1];
                else value /= A[op_pos+1];
                op_pos++;
            }
            values.push_back(value);
            if(op_pos < history.size()) operators.push_back(history[op_pos]);
        }
    }
    int ret = values[0];
    for(int i = 0;i < operators.size();i++) {
        if(operators[i] == 0) ret += values[1+i];
        else ret -= values[1+i];
    }
    return ret;
}

void dfs(int pos) {
    if(pos == N-1) {
        //calculate
        int value = calculate();
        answer_max = max(answer_max,value);
        answer_min = min(answer_min,value);    
        return;
    }
    for(int i = 0;i < 4;i++) {
        if(used[i] < ops[i]) {
            used[i]++;
            history.push_back(i);
            dfs(pos+1);
            history.pop_back();
            used[i]--;
        }
    }
}

int main() {  
    cin >> N;
    for(int i = 0;i < N;i++) cin >> A[i];
    for(int i = 0;i < 4;i++) cin >> ops[i];
    dfs(0);
    cout << answer_max << "\n" << answer_min;
    return 0;
}