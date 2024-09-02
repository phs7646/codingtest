#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int,int> pp;

int main() {
    int D,N; cin >> D >> N;
    vector<pp> diameters;
    int first; cin >> first;
    diameters.emplace_back(first,0);
    int last = first;
    for(int d = 1;d < D;d++) {
        int c; cin >> c;
        if(c > last) continue;
        diameters.emplace_back(c,d); // d깊이에 c길이의 공간
        last = c;
    }
    reverse(diameters.begin(),diameters.end());
    //diameters는 오름차순으로 정렬되어있음
    int cur = D; //현재 cur깊이에 피자가 쌓여있음
    for(int n = 0;n < N;n++) {
        int dia; cin >> dia;
        //cout << "cur : " << dia << endl;
        //dia보다 작은 원판 찾기
        auto it = lower_bound(diameters.begin(),diameters.end(),make_pair(dia,0));
        int target = -1;
        if(it == diameters.begin()) {
            target = D;
        } else {
            target = (it-1)->second;
        }
        //cout << "Found diameter : " << it->second << endl;
        target = min(target,cur)-1; //해당 원판 또는 이미 있는 피자 중 더 작은 곳에 쌓임
        if(target < 0) {
            cout << 0;
            exit(0);
        }
        cur = target;
        //cout << "load to " << target << endl;
    }
    cout << cur+1;
    return 0;
}