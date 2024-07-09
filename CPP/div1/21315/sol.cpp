#include <iostream>
#include <vector>

using namespace std;

int N;

vector<int> shuffle(vector<int>& prev, int k) {
    vector<int> ret(N,0);
    
    
    int num = 1<<k;
    int pos = 0;
    for(;pos < N-num;pos++) {
        ret[num+pos] = prev[pos];
    }
    num>>=1;
    while(num > 0) {
        for(int i = 0;i < num;i++) {
            ret[num+i] = prev[pos++];
        }
        num >>= 1;
    }
    ret[0] = prev[pos];
    return ret;
}

int main() {
    cin >> N;
    vector<int> cards(N);
    for(int i = 0;i < N;i++) cin>>cards[i];
    vector<int> origin;
    for(int i = 1;i <=N;i++) origin.push_back(i);
    int max_k = 0;
    int value = 1;
    while(value <= N) {
        max_k++;
        value <<= 1;
    }
    for(int k1 = 1;k1 < max_k;k1++) {
        vector<int> afterk1 = shuffle(origin,k1);
        for(int k2 = 1;k2 < max_k;k2++) {
            vector<int> afterk2 = shuffle(afterk1,k2);
            bool flag = true;
            for(int i = 0;i < N;i++) {
                if(cards[i] != afterk2[i]) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                cout << k1 << " " << k2;
                return 0;
            }
        }
    }
    return 0;
}