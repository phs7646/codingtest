#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define bignum 200007

int dfs(vector<int>& v,vector<int>& accum,int i,int val) {
	//i번쨰부터 써서 val이상 만들 때 최소 값
	if(val <= 0) return 0;
	if(i >= v.size()) return bignum;
	if(accum[i] < val) return bignum;
	if(accum[i] == val) return val;
	//선택하거나 하지않거나
	return min(dfs(v,accum,i+1,val),v[i]+dfs(v,accum,i+1,val-v[i]));
}

int main(int argc, char** argv)
{
	int T;cin >>T;
	for(int t = 1;t <= T;t++) {
		int N,B;
		cin >> N >> B;
		int sum = 0;
		vector<int> v(N);
		vector<int> accum(N);
		for(int i = 0;i < N;i++) {
			cin >> v[i];
			sum += v[i];
		}
		sort(v.begin(),v.end(),greater<int>());
		accum[N-1] = v[N-1];
		for(int i = N-2;i >= 0;i--) {
			accum[i] = accum[i+1] + v[i];
		}
		
		int answer = sum;	
		for(int i = 0;i < N;i++) {
			if(sum < B) break;
			//i-1번까지 사용 x, i번째를 반드시 사용
			answer = min(answer,v[i]+dfs(v,accum,i+1,B-v[i]));
			sum -= v[i];
		}
		cout << '#' << t << " " << answer-B << '\n';
	}
	return 0;
}