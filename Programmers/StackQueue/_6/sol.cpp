#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    int N = prices.size();
    vector<int> answer(N,0);
    vector<int> alive;
    for(int i = 0;i < N;i++) {
        for(auto it = alive.begin(); it != alive.end();) {
            answer[*it]++;
            if(prices[*it] <= prices[i]) {
                //cout << *it << " alive!\n";
                //still alive
                it++;
            } else {
                //cout << *it << " died\n";
                //die
                it = alive.erase(it);
            }
        }
        alive.push_back(i);
        //cout << i << " pushed\n";
    }
    
    return answer;
}