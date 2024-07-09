#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    stack<int> s;
    int count = 0;
    for(int i = 0;i < N;i++) {
        int x,y;
        cin >> x >> y;
        if(s.empty() || s.top() < y) {
            if(y != 0) s.push(y);
        } else {
            while(!s.empty() && s.top() > y) {
                count++;
                s.pop();
            }
            if(y != 0 && (s.empty() || s.top() != y)) s.push(y);
        }
    }
    count += s.size();
    cout << count;
    return 0;
}