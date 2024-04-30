#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/* helper functions */

template<typename T>
void vectorprint(vector<T>& v) {
    for(T t : v) cout << t << " ";
    cout << "\n";
}

template<typename T>
vector<T> vectorinput(int n) {
    vector<T> ret(n);
    for(int i = 0;i < n;i++) cin >> ret[i];
    return ret;
}

template<typename Iterator>
bool my_next_permutation(Iterator first, Iterator last) {
    if (first == last) return false;  // 리스트 길이 1
    if (first+1 == last && *first < *last) { // 리스트 길이 2
        swap(*first,*last);
        return true;
    }

    Iterator it = last - 1;
    while (it != first) {
        Iterator it3 = it - 1;
        if (*it > *it3) {
            Iterator it2 = last;
            while (!(*--it2 > *it3)); // it3보다 큰 첫 번째 요소 찾기
            std::swap(*it3, *it2);
            std::reverse(it, last); // it 부터 last까지 뒤집기
            return true;
        }
        it--;
    }

    return false; // 전체 범위가 내림차순으로 정렬되어 있을 때
}



/* codes */

int main() {
    int T;
    cin >> T;
    for(int t = 0;t < T;t++) {
        string s;
        cin >> s;
        string s2 = s;
        //if(next_permutation(s2.begin(),s2.end())) {
        if(my_next_permutation(s2.begin(),s2.end())) {
            cout << s2 << "\n";
        } else cout << s << "\n";
    }
    return 0;
}


