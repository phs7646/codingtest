#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <sstream>
using namespace std;
int myMax = 1000000001;

unordered_map<string,int> memo;
unordered_map<string,vector<vector<pair<int,string>>>> recipes;
unordered_map<string,bool> calculated;
vector<string> calculating;

int calculate(string target) {
    //cout << "Call " << target << "\n";
    if(calculated[target]) return memo[target];
    
    //set calculating
    if(find(calculating.begin(),calculating.end(),target) != calculating.end()) {
        //dead lock
        //calculating.erase(find(calculating.begin(),calculating.end(),target));
        //calculated[target] = true;
        //memo[target] = -1;
        //cout << target << " is " << memo[target] << "\n";
        //if(memo[target] > 0) return memo[target];
        return -1;
    }

    //must calculate
    calculating.push_back(target);

    //start calculating
    int ret = INT_MAX;
    if(memo[target] > 0) ret = memo[target]; //if initial price is set..
    for(vector<pair<int,string>> recipe : recipes[target]) {
        int value = 0;
        for(const auto& pair : recipe) {
            int time = pair.first;
            int cost = calculate(pair.second);
            if(cost == -1) {
                //this recipe is impossible
                value = -1;
                break;
            }
            long long current = static_cast<long long>(time) * static_cast<long long>(cost);
            if(current >= static_cast<long long>(myMax)) value += myMax;
            else value += static_cast<int>(current);
            if(value >= myMax) value = myMax;
        }
        if(value != -1 && value < ret) ret = value;
    }

    //return
    if(ret == INT_MAX) ret = -1;
    calculating.erase(find(calculating.begin(),calculating.end(),target));
    if(ret != -1) {
        calculated[target] = true;
        memo[target] = ret;
    }
    //cout << target << " is " << memo[target] << "\n";
    return ret;
}

int main() {
    int N,M;
    cin >> N >> M;
    for(int i = 0;i < N;i++) {
        string ing;
        int price;
        cin >> ing >> price;
        memo[ing] = price;
    }

    cin.ignore();
    string input;
    for(int i = 0;i < M;i++) {
        getline(cin,input);
        size_t eqaulpos = input.find('=');
        string potion = input.substr(0,eqaulpos);
        string formula = input.substr(eqaulpos+1);

        vector<pair<int, string>> recipe;
        stringstream ss(formula);
        string component;

        while (getline(ss, component, '+')) {
            int quantity = component[0] - '0';
            string ingredient = component.substr(1);
            recipe.push_back(make_pair(quantity, ingredient));
        }
        recipes[potion].push_back(recipe);
    }

    cout << calculate("LOVE");

    return 0;
}