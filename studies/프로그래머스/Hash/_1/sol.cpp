#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_map<int,int> map;
    for(int n : nums) map[n]++;
    
    return min(map.size(),nums.size()/2);
}