#include <iostream>
#include <random>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 시드 생성. 시간 기반 시드를 사용하여 매번 다른 난수를 생성.
    std::random_device rd; 
    std::mt19937 gen(rd());
    // 1 이상 10^8 이하의 정수 범위 설정
    std::uniform_int_distribution<> dis(1, 10000);

    int T = 40;
    cout << T << endl;
    // 랜덤한 정수 생성
    for(int t = 1;t <= T;t++) {
        vector<int> v;
        v.push_back(dis(gen));
        v.push_back(dis(gen));
        v.push_back(dis(gen));
        sort(v.begin(),v.end());
        cout << v[2] << " " << v[0] << " " << v[1] << endl;
    }

    return 0;
}
