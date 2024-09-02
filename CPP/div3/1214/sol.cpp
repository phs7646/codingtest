#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    long long D,P,Q; cin >> D >> P >> Q;
    if(D%P == 0 || D%Q == 0) {
        cout << D;
        return 0;
    }
    if(P<Q) {//set bigger one as P
        long long tmp = P;
        P = Q;
        Q = tmp;
    }
    //P를 최대로 고르기
    int max_P = D/P + 1;
    int answer = max_P * P;
    for(int i = max_P-1; i >= 0;i--) {
        //P를 i개 내고, 나머지는 Q로 채우자
        long long cur = P*i;
        long long remain = D - cur;
        if(remain % Q == 0) { //완벽한 방법을 찾았다
            cout << D;
            return 0;
        }
        int newCost = cur + (remain+Q-1)/Q*Q;
        if(newCost == answer) break; //가지치기 : 최소공배수 때문에..
        answer = min(answer,newCost);
    }
    cout << answer;    
}