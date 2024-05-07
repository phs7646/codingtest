#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string,int> counter;
    for(vector<string> v : clothes) {
        counter[v[1]]++;
    }
    int answer = 1;
    for(auto pair : counter) {
        answer *= pair.second+1;
    }
    return answer-1;
}