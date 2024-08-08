    #include<iostream>
    #include<map>
    #include<algorithm>
    #include<vector>
    #include<climits>
    using namespace std;

    typedef long long ll;

    int main() {
        int N; cin >> N;
        vector<ll> A(N);
        vector<ll> B(N);
        for(int i = 0;i < N;i++) cin >> A[i];
        for(int i = 0;i < N;i++) cin >> B[i];
        ll S = 0; //전부다 B에 넣었을때 차이
        vector<ll> V(N);
        for(int i = 0;i < N;i++) {
            V[i] = A[i] + B[i]; //i번을 고르면 차이가 V[i]만큼 줄어듦
            S += A[i];
        }
        int halfN = N/2;
        vector<map<ll,ll>> dp1(halfN+1); //value -> bit
        vector<map<ll,ll>> dp2(halfN+1);

        //build dp
        ll max_bit = (1 << halfN);

        for(ll bit = 0; bit < max_bit; bit++) {
            //해당 비트가 몇개를 고른 비트인지 계산
            int picked = 0;
            ll _bit = bit;
            while(_bit > 0) {
                if(_bit & 1) picked++;
                _bit >>= 1;
            }

            //해당 bit로 골랐을때 value 계산
            ll valueleft = 0;
            ll valueright = 0;
            for(int i = 0;i < halfN;i++) {
                if(bit & (1L<<i)) {
                    valueleft += V[halfN-i-1];
                    valueright += V[N-i-1];
                }
            }
            //map update
            map<ll,ll>& target1 = dp1[picked];
            auto it1 = target1.find(valueleft);
            if(it1 == target1.end()) target1[valueleft] = (bit << halfN);
            else it1->second = min(it1->second,(bit << halfN)); //같은 value라면 bit가 작은게 이득(사전순으로 먼저옴)
            map<ll,ll>& target2 = dp2[picked];
            auto it2 = target2.find(valueright);
            if(it2 == target2.end()) target2[valueright] = bit;
            else it2->second = min(it2->second,bit);
        }

        ll answer_abs = LLONG_MAX;
        ll answer_bit = LLONG_MAX;
        //find answer
        for(int a = 0;a <= halfN;a++) {
            int b = halfN - a; //왼쪽에서 a개, 오른쪽에서 b개
            for(pair<ll,ll> p : dp1[a]) {
                ll lvalue = p.first;
                ll lbit = p.second;
                auto it = dp2[b].lower_bound(S-lvalue); //S-lvalue에 가장 가까운 값 찾기
                //it과 it-1 두가지를 조회해야함 
                if(it != dp2[b].end()) {
                    //it 조회
                    ll _abs = abs(S - (lvalue + (it->first)));
                    ll _bit = lbit + it->second;
                    if(_abs < answer_abs || (_abs == answer_abs && _bit < answer_bit)) {
                        answer_abs = _abs;
                        answer_bit = _bit;
                    }
                }
                if(it != dp2[b].begin()) {
                    //it-1조회
                    it--;
                    ll _abs = abs(S - (lvalue + (it->first)));
                    ll _bit = lbit + it->second;
                    if(_abs < answer_abs || (_abs == answer_abs && _bit < answer_bit)) {
                        answer_abs = _abs;
                        answer_bit = _bit;
                    }
                }
            }
        }
        //print
        for(int i = N-1; i>=0;i--) {
            if(answer_bit & (1L<<i)) cout << "2 ";
            else cout << "1 ";
        }
        return 0;
    }