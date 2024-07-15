#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int T; cin >> T;

    for (int t = 1; t <= T; t++) {
        int N,A,B;
        cin >> N >> A >> B;

        //예외 처리
        if(N < A) {
            cout << '#' << t << " " << -1 << "\n";
            continue;
        }
        if(N <= B) {
            cout << '#' << t << " " << 0 << "\n";
            continue;
        }
        if(N % B == 0) {
            long long answer = 0;
            int remain = N-B;
            while(remain >= B) {
                answer += (long long) B * remain;
                remain -= B;
            }
            cout << '#' << t << " " << answer << "\n";
            continue;
        }
        if(A==B) {
            cout << '#' << t << " " << -1 << "\n";
            continue;
        }

        //로직
        int numB = N/B + 1;
        int numA = N/A;
        if(N%A != 0) numA++;
        //numB 이상 numA이하의 덩어리들을 만들어야함
        int cur_num = numB;
        long long answer = -1;
        while(cur_num <= numA) {
            //만들 수 있는가?
            int max_possib = cur_num * B;
            int min_possib = cur_num * A;
            if(N > max_possib || min_possib > N) continue;
            //만들 수 있음. 반드시 만듦!
            int vari = B-A;
            int havetogo = max_possib - N;
            int remain = N;
            answer = 0;
            while(havetogo > 0) {
                if(havetogo >= vari) {
                    //detach A
                    answer += (long long) A * (remain-A);
                    remain -= A;
                    havetogo -= vari;
                } else {
                    //detach B-havetogo
                    int detach = B-havetogo;
                    answer += (long long) detach * (remain - detach);
                    remain -= detach;
                    havetogo = 0;
                }
            }
            //여기서 remain은 반드시 B의 배수임
            while(remain > 0) {
                answer += (long long) B * (remain-B);
                remain -= B;
            }
            break;
        }

        
        cout << '#' << t << " " << answer << "\n";
    }

    return 0;
}
