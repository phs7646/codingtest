#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> v1(N);
    vector<int> v2(N);
    vector<pair<int,int>> score(N);
    for(int i = 0;i < N;i++) {
        cin >> v1[i];
    }
    for(int i = 0;i < N;i++) {
        cin >> v2[i];
    }
    for(int i = 0;i < N;i++) {
        int n;
        cin >> n;
        score[N-n] = {v1[i],v2[i]};
    }
    int max1 = 0;
    int max2 = 0;

    int count = 0;
    for(int i = 0;i < N;i++) {
        if(score[i].first > max1 && score[i].second > max2) count++;
        max1 = max(max1,score[i].first);
        max2 = max(max2,score[i].second);
    }

    cout << count << "\n";
    
    for(auto pair : score) {
        cout << pair.first << "," << pair.second << "\n";
    }

    return 0;
}