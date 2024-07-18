#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<cassert>
using namespace std;

string addLongLongStrings(long long a, long long b, long long c) {
    // Convert the long long integers to strings
    string sa = to_string(a);
    string sb = to_string(b);
    string sc = to_string(c);

    // Reverse the strings to simplify addition from least significant digit
    reverse(sa.begin(), sa.end());
    reverse(sb.begin(), sb.end());
    reverse(sc.begin(), sc.end());

    // Find the maximum length of the strings
    int maxLength = max({sa.length(), sb.length(), sc.length()});

    // Initialize variables for the sum and carry
    string sum;
    int carry = 0;

    // Add the strings from right to left
    for (int i = 0; i < maxLength; ++i) {
        int digitA = i < sa.length() ? sa[i] - '0' : 0;
        int digitB = i < sb.length() ? sb[i] - '0' : 0;
        int digitC = i < sc.length() ? sc[i] - '0' : 0;

        int digitSum = digitA + digitB + digitC + carry;
        carry = digitSum / 10;
        sum += (digitSum % 10) + '0';
    }

    // If there is a remaining carry, add it to the sum
    if (carry > 0) {
        sum += carry + '0';
    }

    // Reverse the sum to get the correct order
    reverse(sum.begin(), sum.end());

    return sum;
}

long long calcul(int A, int numA) {
    if(numA == 0) return 0;
    if(numA == 1) return 0;
    //A인 덩어리 numA개
    long long ret = 0;
    long long remain = A*numA - A;
    while(remain >= A) {
        ret += A * remain;
        remain -= A;
    }
    return ret;
    long long whole = static_cast<long long>(A) * numA;
    long long part1 = whole * numA;
    long long part2 = (static_cast<long long>(numA) * (numA + 1) / 2) * A;
    return A * (part1 - part2);
}
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int T; cin >> T;

    for (int t = 1; t <= T; t++) {
        int N, A, B;
        cin >> N >> A >> B;

        // 예외 처리
        if (N < A) {
            cout << '#' << t << " " << -1 << "\n";
            continue;
        }
        if (N <= B) {
            cout << '#' << t << " " << 0 << "\n";
            continue;
        }
        if (N % B == 0) {
            cout << '#' << t << " " << calcul(B,N/B) << "\n";
            continue;
        }
        if (A == B) {
            cout << '#' << t << " " << -1 << "\n";
            continue;
        }
        
        //로직

        int numB = N / B;
        int remain = N % B; //0보다 크고 A보다 작음. 따라서 최소 1개 이상의 B를 빌려와야함
        if(remain >= A) {
            cout << '#' << t << " " << calcul(B,N/B) + remain * (B*numB) << "\n";
            continue;
        }
        int diff = B-A; //0보다 큼
        int k = (A-remain+diff-1)/diff; // (A-rem)/diff 의 올림 : 빌려와야 하는 B의 최솟값
        if(k > numB) {
            cout << '#' << t << " " << -1 << "\n";
            continue;
        }
        //이제 k*B + remain 을 k+1개의 덩어리로 분할할 수 있음이 보장됨
        int left = k*B+remain - (k+1) * A; // 마지막 덩어리를 k+1 개의 A의 덩어리로 나눔 이때 남는 left를 이중 한덩어리에 얹으면됨.
        numB -= k;
        //B 가 numB개, A가 k개, A+left 하나
        long long last = A + left;
        long long totB = B * numB;
        long long totA = A * k;
        //long long answer = calcul(A,k) + calcul(B,numB) + totA * totB +  last * totA + last * totB;
        cout << '#' << t << " " << addLongLongStrings(calcul(A,k),calcul(B,numB),totA*totB+last*totA+last*totB) << "\n";
    }

    return 0;
}
