#include<iostream>
#include<vector>
using namespace std;


int N,K;
vector<int> S;
vector<int> possib;
vector<int> choosen(8);
vector<bool> canuse(10);
int chooselen;
vector<int> current;
bool next() {
    current[0]++;
    for(int i = 0;i < chooselen-1;i++) {
        if(current[i] < K) break;
        current[i] = 0;
        current[i+1]++;
    }
    if(current[chooselen-1] >= K) return false;
    return true;
}

int main() {
    cin >> N;
    S.resize(N);
    for(int i = 0;i < N;i++) cin >> S[i];
    cin >> K;
    possib.resize(K);
    for(int i = 0;i < K;i++) {
        cin >> possib[i];
        canuse[possib[i]] = true;
    }
    chooselen = S[0] + S[1];
    current.resize(chooselen);
    for(int i = 0; i < chooselen;i++) current[i] = 0;
    int answer = 0;
    //완탐
    do {
        //build A and B
        int A = 0;
        for(int i = 0;i < S[0];i++) {
            A = 10 * A + possib[current[i]];
        }
        int B = 0;
        for(int i = S[0];i < chooselen;i++) {
            B = 10 * B + possib[current[i]];
        }
        bool flag = true;
        //check mideum line
        for(int i = S[0];i < chooselen;i++) {
            int ret = A * possib[current[i]];
            //길이, 각 int를 만족해야함.
            vector<int> elements;
            while(ret > 0) {
                elements.push_back(ret%10);
                ret = ret/10;
            }
            if(elements.size() != S[i-S[0] + 2]) {
                flag = false;
                break;
            }
            for(int e : elements) {
                if(!canuse[e]) {
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
        }
        if(!flag) continue;
        //check last line
        int ret = A * B;
        vector<int> elements;
        while(ret > 0) {
            elements.push_back(ret%10);
            ret = ret/10;
        }
        if(elements.size() != S[N-1]) continue;
        for(int e : elements) {
            if(!canuse[e]) {
                flag = false;
                break;
            }
        }
        if(flag) answer++;
    } while(next());
    cout << answer;

    return 0;
}