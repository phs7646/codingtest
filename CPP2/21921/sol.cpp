#include<iostream>
#include<vector>

using namespace std;

int main() {
    int N,X;
    cin >> N >> X;
    vector<int> visit(N);
    for(int i = 0;i < N;i++) cin >> visit[i];
    
    int sum = 0;
    for(int i = 0;i < X;i++) sum += visit[i];
    int max_visit = sum;
    int max_count = 1;
    for(int i = 0;i < N-X;i++) {
        sum-=visit[i];
        sum+=visit[i+X];
        if(max_visit < sum) {
            max_visit = sum;
            max_count = 1;
        } else if (max_visit == sum) {
            max_count++;
        }
    }
    if(max_visit == 0) {
        cout << "SAD";
    } else {
        cout << max_visit << "\n" << max_count;
    }
    return 0;
}