#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <bitset>

using namespace std;

int D, W, K;
vector<int> answerBits;
vector<int> originalBit;

bool isBitOK(int bit) {
    // 해당 bit가 answerBits 중 하나라도 포함하면 true
    for(int answer : answerBits) {
        if((bit & answer) == answer) return true;
    }
    return false;
}

int applyMask(int original, int change_bit, int case_bit) {
    int zeroMasking = ~0;
    int oneMasking = 0;
    int count = 0;
    for(int j = 0; j < D; j++) {
        if((change_bit & (1 << j)) > 0) {
            if((case_bit & (1 << count)) > 0) {
                // 해당 비트를 1로 마스킹
                oneMasking |= 1 << j;
            } else {
                // 해당 비트를 0으로 마스킹
                zeroMasking &= ~(1 << j);
            }
            count++;
        }
    }
    return (original & zeroMasking) | oneMasking;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    stringstream sb;

    for(int t = 1; t <= T; t++) {
        cin >> D >> W >> K;

        // answerBits 만들기
        answerBits.clear();
        int answerbit = (1 << K) - 1;
        for(int i = 0; i <= D - K; i++) {
            answerBits.push_back(answerbit);
            answerbit <<= 1;
        }

        // originalBit 입력받기
        originalBit.assign(W, 0);
        for(int i = 0; i < D; i++) {
            for(int j = 0; j < W; j++) {
                int b;
                cin >> b;
                if(b == 1) originalBit[j] |= (1 << i);
            }
        }

        // 검사 대상 비트 만들기
        vector<vector<int>> changes(D + 1);
        int max_bit = (1 << D) - 1;
        for(int bit = 0; bit <= max_bit; bit++) {
            int count = __builtin_popcount(bit);
            changes[count].push_back(bit);
        }

        // 0개 바꾸는 것부터 검사하기
        bool found = false;
        for(int num_change = 0; num_change <= D && !found; num_change++) {
            for(int change_bit : changes[num_change]) {
                int max_case = (1 << num_change);
                for(int case_bit = 0; case_bit < max_case; case_bit++) {
                    bool flag = true;
                    for(int j = 0; j < W; j++) {
                        int bit = applyMask(originalBit[j], change_bit, case_bit);
                        int bit2 = bit ^ ((1 << D) - 1); // flip
                        if(!isBitOK(bit) && !isBitOK(bit2)) {
                            flag = false;
                            break;
                        }
                    }
                    if(flag) {
                        sb << "#" << t << " " << num_change << "\n";
                        found = true;
                        break;
                    }
                }
                if(found) break;
            }
        }

        if(!found) {
            sb << "#" << t << " " << D << "\n";
        }
    }

    cout << sb.str();

    return 0;
}
