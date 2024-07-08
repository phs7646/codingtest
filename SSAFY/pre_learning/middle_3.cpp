#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main(int argc, char** argv)
{
	int T;
	cin >> T;
	for(int t = 0;t < T;t++) {
		vector<int> Long;
		vector<int> Short;
		int N,M;
		cin >> N >> M;
		if(N >= M) {
			Long.resize(N);
			Short.resize(M);
			for(int i = 0;i < N;i++) cin >> Long[i];
			for(int i = 0;i < M;i++) cin >> Short[i];
		} else {
			Long.resize(M);
			Short.resize(N);
			for(int i = 0;i < N;i++) cin >> Short[i];
			for(int i = 0;i < M;i++) cin >> Long[i];
		}
		int answer = INT_MIN;
		int maxpad = abs(N-M);
		int length = min(N,M);
		for(int pad = 0;pad <= maxpad;pad++) {
			int count = 0;
			for(int i = 0;i < length;i++) {
				count += Short[i] * Long[pad+i];
			}
			answer = max(answer,count);
		}
		cout << "#" << t+1 << " " << answer << "\n";
	}
	return 0;
}