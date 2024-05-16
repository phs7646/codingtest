#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;

vector<double> value(26);

vector<pair<bool,double>> evaluate(const vector<pair<bool,double>>& v) {
    vector<pair<bool,double>> ret;
    for(int i = 0;i < v.size();i++) {
        if(i < v.size()-2 && v[i].first && v[i+1].first && !v[i+2].first) {
            double newvalue = 0;
            if(v[i+2].second == 0) {
                newvalue = v[i].second + v[i+1].second;
            } else if(v[i+2].second == 1) {
                newvalue = v[i].second - v[i+1].second;
            } else if(v[i+2].second == 2) {
                newvalue = v[i].second * v[i+1].second;
            } else {
                newvalue = v[i].second / v[i+1].second;
            }
            ret.push_back({true,newvalue});
            i += 2;
        }
        else ret.push_back(v[i]);
    }
    return ret;
}

int main() {
    int N;
    cin >> N;
    string s;
    cin >> s;
    for(int i = 0;i < N;i++) cin>>value[i];
    vector<pair<bool,double>> v; // {true,value} or {false,char} : +-*/

    for(char c : s) {
        if('A' <= c && c <= 'Z') v.push_back({true,value[c-'A']});
        else if (c == '+') v.push_back({false,0});
        else if (c == '-') v.push_back({false,1});
        else if (c == '*') v.push_back({false,2});
        else if (c == '/') v.push_back({false,3});
    }

    while(v.size() > 1) {
        v = evaluate(v);
    }
    cout << fixed << setprecision(2)<< v[0].second;

    return 0;
}