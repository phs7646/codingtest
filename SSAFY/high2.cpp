#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

int reveal(int N,vector<string>& board,int i,int j) {
	int count = 0;
	for(int y = i-1; y <= i+1; y++) {
		if(y < 0 || y >= N) continue;
		for(int x = j-1; x <= j+1; x++) {
			if(x < 0 || x >= N) continue;
			if(board[y][x] == '*') count++; 
		}
	}
	board[i][j] = '0' + count;
	return count;
}

int main(int argc, char** argv)
{
	int T;cin >>T;
	for(int t = 1;t <= T;t++) {
		int N;
		cin >> N;
		vector<string> board(N);
		vector<vector<bool>> marked(N,vector<bool>(N));
		for(int i = 0;i < N;i++) cin >> board[i];
		int answer = 0;
		//그리디하게 0인점을 누른다.
		for(int i = 0;i < N;i++) {
			for(int j = 0;j < N;j++) {
				if(board[i][j] != '.') continue;
				if(reveal(N,board,i,j) > 0) continue;
				//클릭
				marked[i][j] = true;
				answer++;
				queue<pair<int,int>> q;
				q.push({i,j});
				while(!q.empty()) {
					auto p = q.front();
					q.pop();
					for(int y = p.first-1; y <= p.first+1; y++) {
						if(y < 0 || y >= N) continue;
						for(int x = p.second-1; x <= p.second+1; x++) {
							if(x < 0 || x >= N) continue;
							marked[y][x] = true;
							if(board[y][x] != '.') continue;
							if(reveal(N,board,y,x) == 0) q.push({y,x});
						}
					}
				}
			}
		}
		//클릭되지 않은 점 클릭
		for(int i = 0;i < N;i++) {
			for(int j = 0;j < N;j++) {
				if(board[i][j] != '*' && !marked[i][j]) answer++;
			}
		}
		cout << '#' << t << " " << answer << "\n";
	}
	return 0;
}