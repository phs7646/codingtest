#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int d,N,M;
    cin >> d >> N >> M;
    vector<int> v(N);
    for(int i = 0;i < N;i++) cin >> v[i];
    sort(v.begin(),v.end());
    vector<int> dist(N+1);
    int prev = 0;
    for(int i = 0;i < N;i++) {
        dist[i] = v[i] - prev;
        prev = v[i];
    }
    dist[N] = d-prev;
    N++;
    int left = 0;
    int right = d;
    int answer = 0;
    while(left <= right) {
        int mid = (left+right)/2;
        //mid거리 유지가 가능한가?
        int count = 0;
        int accum = 0;
        for(int i = 0;i < N;i++) {
            if(accum + dist[i] >= mid) {
                accum = 0;
                continue;
            }
            count++;
            accum += dist[i];
        }
        if(count <= M) {
            //가능하다. 범위를 높여서 찾는다.
            answer = max(answer,mid);
            left = mid+1;
        } else {
            //불가능하다. 범위를 낮춰서 찾는다.
            right = mid-1;
        }
    }
    cout << answer;
    return 0;
}