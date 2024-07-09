#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
using namespace std;

int myMax = 1000000001;
vector<string> calculating;

vector<string> tokenize(string s) {
    vector<string> ret;
    int prev = 0;
    for(int i = 1; i < s.length();i++) {
        if(s[i] == '+') {
            ret.push_back(s.substr(prev,i-prev));
            prev = i+1;
        }
    }
    ret.push_back(s.substr(prev,s.length()-prev));
    return ret;
}

int solve(string target, unordered_map<string,int>& memo, unordered_map<string, vector<vector<string>>>& rule) {
    if(memo[target] > 0) return memo[target];
    //start calculate
    for(string s : calculating) {
        if(s == target) return -1;
    }
    calculating.push_back(target);

    const vector<vector<string>>& recipes = rule[target];
    if(recipes.empty()) {
        calculating.erase(find(calculating.begin(),calculating.end(),target));
        return -1;
    }
    int min = INT_MAX;
    for(vector<string> v : recipes) {
        vector<int> ings;
        for(string s : v) {
            int ing = solve(s.substr(1,s.length()-1),memo,rule);
            if(ing == -1) {
                ings.push_back(-1);
                break;
            }
            int time = s[0]-'0';
            long long value = static_cast<long long>(ing) * static_cast<long long>(time);
            if(value >= static_cast<long long>(myMax)) ings.push_back(myMax);
            else if(value < static_cast<long long>(INT_MAX)) ings.push_back(static_cast<int>(value));
            else ings.push_back(v[10000][0] - '0');
        }
        int count = 0;
        for(int ing : ings) {
            if(ing == -1) {
                count = -1;
                break;
            }
            count += ing;
            if(count >= myMax) count = myMax;
        }
        if(count != -1 && min > count) min = count;
    }
    calculating.erase(find(calculating.begin(),calculating.end(),target));
    if(min == INT_MAX) memo[target] = -1;
    else memo[target] = min;
    
    
    return memo[target];
}

int main() {
    int N,M;
    cin >> N >> M;
    unordered_map<string,int> memo;
    unordered_map<string, vector<vector<string>>> rule;
    for(int i = 0;i < N;i++) {
        string s;
        int n;
        cin >> s >> n;
        memo[s] = n;
    }


    vector<string> mustcal;
    for(int i = 0;i < M;i++) {
        string s;
        cin >> s;
        string result;
        int index;
        for(int i = 0;i < s.length();i++) {
            if(s[i] == '=') {
                result = s.substr(0,i);
                index = i;
                break;
            }
        }
        if(memo[result] > 0) {
            mustcal.push_back(result);
        } else memo[result] = -1;
        rule[result].push_back(tokenize(s.substr(index+1,s.length()-index)));
    }
    bool flag = true;
    while(flag) {
        flag = false;
        for(string s : mustcal) {
            int old = memo[s];
            memo[s] = -1;
            solve(s,memo,rule);
            if(memo[s] != -1 && old > memo[s]) {
                flag = true;
            } else memo[s] = old;
        }
    }

    cout << solve("LOVE",memo,rule);
    /*
    cout << "\n";
    for(const auto& pair : memo) {
        cout << "Key : " << pair.first << ", Value : " << pair.second << "\n";
    }
    */

    return 0;
}