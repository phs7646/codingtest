#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int,int>> points(N);
    for(int i = 0;i < N;i++) {
        int a,b;
        cin >> a >> b;
        points[i] = {a,b};
    }
    sort(points.begin(),points.end());
    vector<int> left(N,-1);
    vector<int> maxi(N+1,-1);
    for(int i = 0;i < N;i++) {
        int pos = points[i].first;
        int color = points[i].second;
        if(maxi[color] != -1) {
            left[i] = maxi[color];
        }
        maxi[color] = pos;
    }
    vector<int> mini(N+1,-1);
    vector<int> right(N,-1);
    for(int i = N-1;i >= 0;i--) {
        int pos = points[i].first;
        int color = points[i].second;
        if(mini[color] != -1) {
            right[i] = mini[color];
        }
        
        mini[color] = pos;
    }

    int sum = 0;
    for(int i = 0;i < N;i++) {
        int tmp = points[N-1].first;
        if(left[i] != -1) tmp = min(tmp, points[i].first - left[i]);
        if(right[i] != -1) tmp = min(tmp, right[i] - points[i].first);
        sum += tmp;
    }
    cout << sum;
    return 0;
}