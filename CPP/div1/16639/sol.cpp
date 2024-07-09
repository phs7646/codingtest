#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string s;
int DP[19][19];
bool DPed[19][19];

int calc(int a, char c , int b) {
    //cout << a << " " << c << " " << b << "\n";
    if(c == '+') return a+b;
    if(c == '-') return a-b;
    if(c == '*') return a*b;
    return 0;
}

void sol(int begin,int end) {
    if(begin == end) {
        DP[begin][end] = s[begin]-'0';
        DPed[begin][end] = true;
        return;
    }
    if(DPed[begin][end]) return;
    if(begin+2 == end) {
        DPed[begin][end] = true;
        DP[begin][end] = calc(s[begin] - '0',s[begin+1],s[begin+2] - '0');
        DP[end][begin] = DP[begin][end];
        return;
    }
    int pos = begin+1;
    vector<int> values;
    while(pos < end) {
        sol(begin,pos-1);
        sol(pos+1,end);
        int leftmax = DP[begin][pos-1];
        int leftmin = DP[pos-1][begin];
        int rightmax = DP[pos+1][end];
        int rightmin = DP[end][pos+1];
        values.push_back(calc(leftmax,s[pos],rightmax));
        values.push_back(calc(leftmax,s[pos],rightmin));
        values.push_back(calc(leftmin,s[pos],rightmax));
        values.push_back(calc(leftmin,s[pos],rightmin));
        pos+=2;
    }
    DP[begin][end] = *(max_element(values.begin(),values.end()));
    DP[end][begin] = *(min_element(values.begin(),values.end()));
    return;
}

int main() {
    int N;
    //char trash;
    //cin >> N >> trash;
    cin >> N;
    getline(cin,s);
    getline(cin,s);
    //cout << s << "\n";
    sol(0,N-1);
    cout << DP[0][N-1] << "\n";
    return 0;
}