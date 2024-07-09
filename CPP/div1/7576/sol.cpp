#include  <iostream>
#include <queue>
using namespace std;
int map[1000][1000];
int M,N;
void printMap() {
	for(int i = 0;i < N;i++) {
		for(int j = 0;j < M;j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
int  main()
{
	cin >> M >> N;

	int i,j;
	int yet = 0;
	queue<pair<int,int>> q;
	for(i = 0;i < N;i++) {
		for(j = 0;j < M;j++) {
			cin >> map[i][j];
			if(map[i][j] == 0) yet++;
			if(map[i][j] == 1) q.push(make_pair(i,j));
		}
	}

	if(yet == 0) {
		cout << 0;
		return 0;
	}
	if(q.size() == 0) {
		cout << -1;
		return 0;
	}
	int count = 0;
	while(1) {
		//printMap();
		int num = q.size();
		for(int t = 0;t < num;t++) {
			pair<int,int> p = q.front();
			q.pop();
			int i = p.first;
			int j = p.second;
			if(i>=1 && map[i-1][j] == 0) {
				map[i-1][j] = 1;
				q.push(make_pair(i-1,j));
				yet--;
			}
			if(j>=1 && map[i][j-1] == 0) {
				map[i][j-1] = 1;
				q.push(make_pair(i,j-1));
				yet--;
			}
			if(i < N-1 && map[i+1][j] == 0) {
				map[i+1][j] = 1;
				q.push(make_pair(i+1,j));
				yet--;
			}
			if(j < M-1 && map[i][j+1] == 0) {
				map[i][j+1] = 1;
				q.push(make_pair(i,j+1));
				yet--;
			}
		}
		count++;
		if(yet == 0) {
			cout << count;
			return 0;
		} 
		if(q.size() == 0) {
			cout << -1;
			return 0;
		}
	}

	
}