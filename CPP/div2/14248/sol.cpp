#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0;i < N;i++) cin >> A[i];
    vector<bool> visited(N);
    queue<int> q;
    int s;
    cin >> s;
    visited[s-1] = true;
    q.push(s-1);
    while(!q.empty()) {
        int tar = q.front();
        q.pop();
        int right = tar + A[tar];
        if(right < N && !visited[right]) {
            visited[right] = true;
            q.push(right);
        }
        int left = tar - A[tar];
        if(left >= 0 && !visited[left]) {
            visited[left] = true;
            q.push(left);
        }
    }
    int count = 0;
    for(int i = 0;i < N;i++) if(visited[i]) count++;
    cout << count;
    return 0;
}