#include<iostream>
#include<vector>

using namespace std;

int main() {

    return 0;
}



/* helpers */

template<typename T>
vector<T> vectorinput(T n) {
    vector<T> ret(n);
    for(int i = 0;i < n;i++) cin >> ret[i];
    return ret;
}

template<typename T>
void vectorprint(vector<T>& v) {
    for(T t : v) cout << t << " ";
    cout << "\n";
}