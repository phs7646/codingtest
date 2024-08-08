#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
long long arr[36];
map<long long,long long> dp1[19]; //length - value : bit
map<long long,long long> dp2[19];
long long A[36];
long long B[36];
long long N;
long long answer_abs;
long long answer_bit1;
long long answer_bit2;

bool needupdate(long long bit1,long long bit2) {
    //answer와 비교했을때 업데이트 해야하는가? bit1 + bit2가 사전순으로 더 나중이면 업데이트 해야함
    for(long long i = 0;i < N;i++) {
        long long answer_b = answer_bit1 & (1<<i);
        long long b = bit1 & (1<<i);
        if (answer_b != b) {
            return answer_b < b;
        }
    }
    for(long long i = 0;i < N;i++) {
        long long answer_b = answer_bit2 & (1<<i);
        long long b = bit2 & (1<<i);
        if (answer_b != b) {
            return answer_b < b;
        }
    }
    return false;
}

void updateAnswer(long long abs,long long bit1, long long bit2) {
    //bt1 + bit2 스트링으로 연결한걸 사전순으로 배치해야함.. 
    if(answer_abs < abs) return; //볼 필요 없음
    if(answer_abs > abs || needupdate(bit1,bit2)) {
        answer_abs = abs;
        answer_bit1 = bit1;
        answer_bit2 = bit2;
    }    
} 

int main() {
    cin >> N;
    long long S = 0;
    for(long long i = 0;i < N;i++) cin >> A[i];
    for(long long i = 0;i < N;i++) cin >> B[i];
    for(long long i = 0;i < N;i++) {
        S += B[i];
        arr[i] = A[i]+B[i];
    }
    N >>= 1;
    long long max_bit = 1<<N;
    //N개의 배열 두개로 나눠서 각각 dp 계산
    //dp1 : arr 0 ~ N-1
    for(long long bit = 0;bit < max_bit;bit++) {
        long long picked = 0; //몇개 골라진 비트인가?
        long long _bit = bit;
        while(_bit > 0) {
            if(_bit & 1) picked++;
            _bit >>= 1;
        }
        //양 쪽 배열의 value 계산
        long long value1 = 0;
        long long value2 = 0;
        for(long long i = 0;i < N;i++) {
            if(bit & (1<<i)) {
                value1 += arr[i];
                value2 += arr[N+i];
            }
        }
        //각 map에 업데이트
        map<long long,long long>& target1 = dp1[picked];
        auto it = target1.find(value1);
        if(it != target1.end()) {
            it -> second = min(bit,it->second);
        } else target1[value1] = bit;

        map<long long,long long>& target2 = dp2[picked];
        auto it2 = target2.find(value2);
        if(it2 != target2.end()) {
            it2 -> second = min(bit,it2->second);
        } else target2[value2] = bit;
    }
    //왼쪽 배열에서 a개, 오른쪽배열에서 N-a개 골라서 S에 가장 가깝게 만들기
    //만드는 차이 abs 와 그때의 bit를 유지하고, abs가 같을때 bit를 더 낮게 유지
    answer_abs = S;
    answer_bit1 = 0;
    answer_bit2 = 0;
    for(long long a = 0;a <= N;a++) {
        long long b = N-a; 
        map<long long,long long>& target1 = dp1[a];
        map<long long,long long>& target2 = dp2[b]; //왼쪽에서 a개, 오른쪽에서 b개
        for(auto p : target1) {
            long long left_value = p.first;
            long long left_bit = p.second;
            //left_value와 함께 S에 가장 가까이가는 right_value 찾기
            auto it = target2.lower_bound(S-left_value); //it과 it 왼쪽을 찾아야함!
            if(it != target2.end()) updateAnswer(abs(S-(left_value+it->first)),left_bit,it->second);
            if(it != target2.begin()) {
                it--;
                updateAnswer(abs(S-(left_value+it->first)),left_bit,it->second);
            }
        }
    }
    for(long long i = 0;i < N;i++) {
        if(answer_bit1 & (1<<i)) cout << 1 << " ";
        else cout << 2 << " ";
    }
    for(long long i = 0;i < N;i++) {
        if(answer_bit2 & (1<<i)) cout << 1 << " ";
        else cout << 2 << " ";
    }
    return 0;
}