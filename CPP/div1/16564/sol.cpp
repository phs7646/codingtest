#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    long long K;
    cin >> N >> K;
    vector<long long> X(N);
    for(int i = 0;i < N;i ++) cin >> X[i];
    
    sort(X.begin(),X.end());

    int answer = X[0];
    for(int i = 0;i < N-1;i++) {

        int diff = X[i+1] - X[i];
        if(diff == 0) continue;
        
        int max_raise = K / (i+1); //i까지의 모든 캐릭터들에게 레벨을 나눠줄 때 최대
        if(max_raise >= diff) {
            //이전까지의 모든 캐릭터를 X[i+1]까지 올릴 수 있음
            answer += diff;
            K -= diff * (i+1);   
        } else {
            //이전까지의 모든 캐릭터를 max_raise만큼 올릴 수 있음. 이 때 break
            answer += max_raise;
            K -= max_raise * (i+1);
            break;
        }
    }

    //K가 남았다면 모두에게 공평하게 나눠줌
    if(K > 0) {
        answer += K/N;
    }
    cout << answer;
    return 0;
}