#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <sstream>
using namespace std;
long long myMax = 1000000001;

unordered_map<string,long long> memo;
vector<pair<string,vector<pair<int,string>>>> recipes;
unordered_map<string,bool> calculated;
vector<string> calculating;

void printMemo() {
    cout << "Printing Memo...\n";
    for(pair<string,long long> p : memo) {
        cout << p.first << " :" << p.second << "\n";
    }
    cout << "End of Memo...\n";
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
        recipes.push_back({potion,recipe});
    }
    //printMemo();
    for(int i = 0; i < M;i++) {
        for(auto& recipe : recipes) {
            string potion = recipe.first;
            long long current = 0;
            for(auto& ing : recipe.second) {
                int quantity = ing.first;
                string ingredient = ing.second;
                if(memo[ingredient] <= 0) {
                    current = 0;
                    break;
                }
                current += quantity * memo[ingredient];
                if(current > myMax) current = myMax;
            }
            if(current > 0 && (memo[potion] == 0 || current < memo[potion])) memo[potion] = current;
        }
        //printMemo();
    }
    if(memo["LOVE"] == 0) cout << -1;
    else cout << memo["LOVE"];
    return 0;
}