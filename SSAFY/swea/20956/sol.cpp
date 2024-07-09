#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    int T; cin >> T;
    for(int t = 1; t <= T;t++) {
        string s,e;
        cin >> s; cin >> e;
        int s_Y = 0;
        int e_Y = 0;
        for(char c : s) if(c == 'Y') s_Y++;
        for(char c : e) if(c == 'Y') e_Y++;

        if(s_Y > e_Y) {
            cout << '#' << t << " " << "No\n";
            continue;
        }
        bool is_odd = (e_Y-s_Y)%2==1?true:false;
        bool is_end = false;
        if(is_odd) reverse(s.begin(),s.end());
        for(int i = 0;i <= e.size()-s.size();i++) {
            //i번째에서 매칭시도
            if(i > 0 && e[0] == 'X') {
                cout << '#' << t << " " << "No\n";
                is_end = true;
                break;
            }
            bool flag = true;
            for(int j = 0;j < s.size();j++) {
                if(s[j] != e[i+j]) {
                    flag = false;
                    break;
                }
            }
            if(!flag) continue;
            //매칭. 왼쪽 오른쪽 Y갯수 세기
            int Yleft = 0;
            int Yright = 0;
            for(int k = 0;k < i;k++) if(e[k] == 'Y') Yleft++;
            for(int k = i+s.size();k < e.size();k++) if(e[k] == 'Y') Yright++;
            if((!is_odd && Yleft==Yright) || (is_odd && Yleft==Yright+1)) {
                cout << '#' << t << " " << "Yes\n";
                is_end = true;
                break;
            }
        }
        if(!is_end) cout << '#' << t << " " << "No\n";
    }
    return 0;
}