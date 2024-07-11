#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

#define N 4

typedef struct
{

    int strike;

    int ball;

} Result;
int answer[4];
Result query(int guess[])
{
    cout << "Query Called!\n";
    Result ret;
    ret.strike = 0;
    ret.ball = 0;
    bool used[10] = {false};
    for (int i = 0; i < 4; i++)used[answer[i]] = true;
    for (int i = 0; i < 4; i++)
    {
        if (answer[i] == guess[i]) ret.strike++;
        if (used[guess[i]]) ret.ball++;
    }
    ret.ball -= ret.strike;
    return ret;
}

Result myquery(int myguess[], int guess[])
{
    Result ret;
    ret.strike = 0;
    ret.ball = 0;
    bool used[10] = {false};
    for (int i = 0; i < 4; i++)used[myguess[i]] = true;
    for (int i = 0; i < 4; i++)
    {
        if (myguess[i] == guess[i]) ret.strike++;
        if (used[guess[i]]) ret.ball++;
    }
    ret.ball -= ret.strike;
    return ret;
}
void doUserImplementation(int guess[])
{
    set<int> cand;
    for(int a = 0;a <= 6;a++) {
        for(int b = a+1;b <= 7;b++) {
            for(int c = b+1;c <= 8;c++) {
                for(int d = c+1;d <= 9;d++) {
                    vector<int> v;
                    v.push_back(a); v.push_back(b); v.push_back(c); v.push_back(d);
                    do {
                        cand.insert(v[0] * 1000 + v[1] * 100 + v[2] * 10 + v[3]);
                    } while(next_permutation(v.begin(),v.end()));
                }
            }
        }
    }
    guess[0] = 1;
    guess[1] = 2;
    guess[2] = 3;
    guess[3] = 4;
    Result res = query(guess);
    while(true) {
        vector<int> survival(10);
        //update exclude
        set<int> new_cand;
        for(const int& c : cand) {
            int myguess[4] = {c/1000,(c/100)%10,(c/10)%10,c%10};
            Result myres = myquery(myguess,guess);
            if(res.strike == myres.strike && res.ball == myres.ball) {
                //survive combinations
                new_cand.insert(c);
                for(int i = 0;i < 4;i++) survival[myguess[i]]++;
            }
        }
        cand = new_cand;
        //pick next guess
        //전략 : survival 이 0인 숫자 빼고, survival이 작은 숫자 부터 선택해서 최대한 숫자 선택지를 줄인다.
        //디버깅 : 그렇게 고른 4 숫자를 포함하는 후보가 하나도 없을 땐 어떻게해
        //점수를 매김. 4가지 숫자의 생존지수 총합이 가장 낮게
        int best = 9999;
        for(const int& p : cand) {
            int a = p/1000;
            int b = (p/100)%10;
            int c = (p/10)%10;
            int d = p%10;
            if(survival[a] == 0 || survival[b] == 0 || survival[c] == 0 || survival[d] == 0) continue;
            int score = survival[a] + survival[b] + survival[c] + survival[d];
            if(score < best) {
                best = score;
                guess[0] = a; guess[1] = b; guess[2] = c; guess[3] = d;
            }
        }
        res = query(guess);
        if(res.strike == 4) break;
    }
}

int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < 4; i++)
        answer[i] = s[i] - '0';
    int guess[4];
    doUserImplementation(guess);
    return 0;
}