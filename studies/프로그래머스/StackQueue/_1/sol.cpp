#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int prev = arr[0];
    answer.push_back(prev);
    for(int i = 1;i < arr.size();i++) {
        if(arr[i] != prev) {
            answer.push_back(arr[i]);
            prev = arr[i];
        }
    }

    return answer;
}