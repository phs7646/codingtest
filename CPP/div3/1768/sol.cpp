#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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

    for (int i = 0; i < 4; i++)
        ret.ball -= ret.strike;
    return ret;
}



Result myquery(vector<int>& left, int guess[])
{
    Result ret;
    ret.strike = 0;
    ret.ball = 0;
    bool used[10] = {false};
    for (int i = 0; i < 4; i++)used[left[i]] = true;
    for (int i = 0; i < 4; i++)
    {
        if (left[i] == guess[i]) ret.strike++;
        if (used[guess[i]]) ret.ball++;
    }
    for (int i = 0; i < 4; i++)
        ret.ball -= ret.strike;
    return ret;
}
bool exclude[10][10][10][10];
void doUserImplementation(int guess[])
{
    guess[0] = 1;
    guess[1] = 2;
    guess[2] = 3;
    guess[3] = 4;
    Result res = query(guess);
    while(true) {
        vector<pair<int,int>> survival(10);
        for(int i = 0;i < N;i++) survival[i] = {i,0};
        //update exclude
        for(int a = 0;a <= 6;a++) {
            for(int b = a+1;b <= 7;b++) {
                for(int c = b+1;c <= 8;c++) {
                    for(int d = c+1;d <= 9;d++) {
                        vector<int> v;
                        v.push_back(a); v.push_back(b); v.push_back(c); v.push_back(d);
                        do {
                            if(exclude[v[0]][v[1]][v[2]][v[3]]) continue;
                            Result myres = myquery(v,guess);
                            if(res.strike != myres.strike || res.ball != myres.ball) exclude[v[0]][v[1]][v[2]][v[3]] = true;
                            else {
                                //survive combinations
                                survival[a].second++;
                                survival[b].second++;
                                survival[c].second++;
                                survival[d].second++;
                            }
                        } while(next_permutation(v.begin(),v.end()));
                    }
                }
            }
        }
        //pick next guess
        //전략 : survival 이 0인 숫자 빼고, survival이 작은 숫자 부터 선택해서 최대한 경쟁자를 줄인다.
        return;
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