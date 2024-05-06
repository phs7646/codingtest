#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> books(N);
    for(int i = 0;i < N;i++) cin >> books[i];
    sort(books.begin(),books.end());

    int count = 1;
    int current = books[0];
    for(int i = 1;i < N;i++) {
        if(books[i] >= current * 2) {
            current = books[i];
            count++;
        }
    }
    cout << count;
    return 0;
}
