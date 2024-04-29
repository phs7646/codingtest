#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int count = 0;
    for(char c : s) {
        if(c == '(') count++;
        else count--;
        if(count < 0) return false;
    }
    if(count != 0) return false;
    return true;

}