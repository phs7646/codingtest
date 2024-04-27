#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> calculate(vector<int>& v) {
    int size = v.size();
    int howmany = 1 << size;
    vector<long long> ret(howmany);
    for(int i = 0;i < howmany;i++) {
        long long sum = 0;
        int cursor = 0;
        int bit = i;
        while(bit > 0) {
            if((bit & 1) == 1) {
                sum += v[cursor];
            }
            cursor++;
            bit >>= 1;
        }
        ret[i] = sum;
    }
    return ret;
}

int main() {
    int N,S;
    cin >> N >> S;
    int a = N/2;
    int b = N-a;
    vector<int> va(a);
    vector<int> vb(b);
    for(int i = 0;i < a;i++) cin >> va[i];
    for(int i = a;i < N;i++) cin >> vb[i-a];

    vector<long long> suma = calculate(va);
    sort(suma.begin(),suma.end()); //오름차순
    vector<long long> sumb = calculate(vb);
    sort(sumb.begin(),sumb.end(),greater<long long>()); //내림차순
    /*
    for(int n : suma) cout << n << " ";
    cout << "\n";
    for(int n : sumb) cout << n << " ";
    cout << "\n";
    */
    auto ita = suma.begin();
    auto itb = sumb.begin();


    //투포인터 움직이면서 S찾기
    long long answer = 0;
    bool flaga = true;
    bool flagb = true;
    long long valuea,valueb;
    long long counta,countb;
    while(true) {
        //cout << "Call " << valuea << " " << valueb << "\n";
        if(flaga) {
            //ita 같은 수 전부 pop
            if(ita == suma.end()) break;
            valuea = *ita;
            ita++;
            counta = 1;
            while(ita != suma.end() && *ita == valuea) {
                counta++;
                ita++;
            }
            flaga = false;
        }
        if(flagb) {
            //itb 같은 수 전부 pop
            if(itb == sumb.end()) break;
            valueb = *itb;
            itb++;
            countb = 1;
            while(itb != sumb.end() && *itb == valueb) {
                countb++;
                itb++;
            }
            flagb = false;
        }
        //cout << valuea << "," << valueb << "\n";
        int currentS = valuea + valueb;
        if(currentS == S) {
            //cout << "HIT!\n";
            //cout << valuea << "," << valueb << "\n";
            answer += counta * countb;
            flaga = true;
            flagb = true;
        } else if(currentS > S) {
            flagb = true;
        } else {
            flaga = true;
        }
    }
    if(S == 0) answer--;
    cout << answer;

    return 0;
}