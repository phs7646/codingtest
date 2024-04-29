#include "iostream"
#include "string"
using namespace std;

string ReverseFunction(int array[2], const string& InputStr) {
    int a = array[0];
    int b = array[1];
    string retStr = InputStr;
    for(int i = 0; i < b-a;i++) {
        retStr[a + i] = InputStr[b-i];
    }
   return retStr;
}

int main() {
    string str;
    int reverseNum[][2] = { {0,7},{4,6},{5,14},{2,7} };
    getline(cin, str);
    for (int index = 0; index < 4; index++) {
        cout << ReverseFunction(reverseNum[index], str) << endl;
    }
    return 0;
}