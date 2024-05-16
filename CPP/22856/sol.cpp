#include<iostream>
#include<vector>

using namespace std;
int N;
vector<pair<int,int>> childs;
vector<bool> visited;
int answer = 0;
int endoftravel = 0;


bool all(vector<bool> v) {
    for(bool b : v) if(!b) return false;
    return true;
}

void findend(int pos) {
    visited[pos] = true;
    int left = childs[pos].first;
    int right = childs[pos].second;
    if(left >= 0 && visited[left] == false) {
        findend(left);
    }
    endoftravel = pos;
    if(right >= 0 && visited[right] == false) {
        findend(right);
    }
}

void travel(int pos) {
    visited[pos] = true;
    int left = childs[pos].first;
    int right = childs[pos].second;
    if(left >= 0 && visited[left] == false) {
        answer++;
        travel(left);
        answer++;
    }
    if(right >= 0 && visited[right] == false) {
        answer++;
        travel(right);
        answer++;
    }
    if(pos == endoftravel) {
        cout << answer;
        exit(0);
    }
}

int main() {
    cin >> N;
    childs.resize(N);
    for(int i = 0;i < N;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        childs[a-1] = {b-1,c-1};
    }
    visited.resize(N,false);
    findend(0);
    for(int i = 0;i < N;i++)visited[i] = false;
    travel(0);

    return 0;
}