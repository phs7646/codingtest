#include<iostream>
#include<vector>

using namespace std;

int main() {

    return 0;
}

/* helpers */

template<typename T>
void vectorprint(vector<T>& v) {
    for(T t : v) cout << t << " ";
    cout << "\n";
}