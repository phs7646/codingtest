#include<iostream>
#include<vector>
#include<string>
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
    cout << "Query called!";
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
    bool cand[10000] = {false};
    for(int a = 0;a <= 9;a++) {
        for(int b = 0;b <= 9;b++) {
            if(b == a) continue;
            for(int c = 0;c <= 9;c++) {
                if(c == a || c == b) continue;
                for(int d = 0;d <= 9;d++) {
                    if(d == a || d == b || d == c) continue;
                    cand[a*1000 + b*100 + c*10 + d] = true;
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
        int survival[10] = {0};
        //update cand
        for(int a = 0;a <= 9;a++) {
            for(int b = 0;b <= 9;b++) {
                if(b == a) continue;
                for(int c = 0;c <= 9;c++) {
                    if(c == a || c == b) continue;
                    for(int d = 0;d <= 9;d++) {
                        if(d == a || d == b || d == c) continue;
                        if(!cand[a*1000 + b*100 + c*10 + d]) continue;
                        int myguess[4] = {a,b,c,d};
                        Result myres = myquery(myguess,guess);
                        if(res.strike == myres.strike && res.ball == myres.ball) {
                            //survive combinations
                            for(int i = 0;i < 4;i++) survival[myguess[i]]++;
                        } else {
                            //die
                            cand[a*1000 + b*100 + c*10 + d] = false;
                        }
                    }
                }
            }
        }
        //pick next guess
        //전략 : survival 이 0인 숫자 빼고, survival이 작은 숫자 부터 선택해서 최대한 숫자 선택지를 줄인다.
        //디버깅 : 그렇게 고른 4 숫자를 포함하는 후보가 하나도 없을 땐 어떻게해
        //점수를 매김. 4가지 숫자의 생존지수 총합이 가장 낮게
        int best = 9999;
        for(int a = 0;a <= 9;a++) {
            for(int b = 0;b <= 9;b++) {
                if(b == a) continue;
                for(int c = 0;c <= 9;c++) {
                    if(c == a || c == b) continue;
                    for(int d = 0;d <= 9;d++) {
                        if(d == a || d == b || d == c) continue;
                        if(!cand[a*1000 + b*100 + c*10 + d]) continue;
                        int score = survival[a] + survival[b] + survival[c] + survival[d];
                        if(score < best) {
                            best = score;
                            guess[0] = a; guess[1] = b; guess[2] = c; guess[3] = d;
                        }
                    }
                }
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