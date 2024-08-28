package _0828;

/**
 * 메모리 : 98512
 * 실행 시간 : 833
 * Queue를 활용한 구현
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution_2382_미생물격리_박한성 {

	static class Cell {
		int num;
		int max_num;
		int dir;

		Cell() {
		}

		void init() {
			num = 0;
			max_num = 0;
		}
	}
	
	static class Unit {
		int y,x;
		int num;
		int dir;
		public Unit(int y, int x, int num, int dir) {
			super();
			this.y = y;
			this.x = x;
			this.num = num;
			this.dir = dir;
		}
	}

	static int dy[] = {-1,1,0,0};
	static int dx[] = {0,0,-1,1};
	static int oppo(int dir) {
		if(dir == 0) return 1;
		else if(dir == 1) return 0;
		else if(dir == 2) return 3;
		else return 2;
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine().trim());
		for (int t = 1; t <= T; t++) {
			//Input
			StringTokenizer st = new StringTokenizer(br.readLine().trim());
			int N = Integer.parseInt(st.nextToken());
			int M = Integer.parseInt(st.nextToken());
			int K = Integer.parseInt(st.nextToken());
			
			Queue<Unit> q = new LinkedList<>();
			for(int k = 0;k < K;k++) {
				st = new StringTokenizer(br.readLine().trim());
				int y = Integer.parseInt(st.nextToken());
				int x = Integer.parseInt(st.nextToken());
				int num = Integer.parseInt(st.nextToken());
				int dir = Integer.parseInt(st.nextToken())-1;
				q.add(new Unit(y,x,num,dir));
			}
			
			//Initialize
			Cell map[][] = new Cell[N][N];
			for(int i = 0;i < N;i++) {
				for(int j = 0;j < N;j++) {
					map[i][j] = new Cell();
				}
			}
			//Logic
			for(int day = 0;day < M;day++) {
				//move and write into cell
				while(!q.isEmpty()) {
					Unit u = q.poll();
					int ny = u.y + dy[u.dir];
					int nx = u.x + dx[u.dir];
					if(ny == 0 || ny == N-1 || nx == 0 || nx == N-1) {
						//border cell
						map[ny][nx].num = u.num >> 1;
						map[ny][nx].dir = oppo(u.dir);
					} else {
						//normal cell
						if(map[ny][nx].max_num < u.num) {
							map[ny][nx].max_num = u.num;
							map[ny][nx].dir = u.dir;
							map[ny][nx].num += u.num;
						} else {
							map[ny][nx].num += u.num;
						}
					}
				}
				
				//build q again
				for(int i = 0;i < N;i++) {
					for(int j = 0;j < N;j++) {
						if(map[i][j].num > 0) {
							q.add(new Unit(i,j,map[i][j].num,map[i][j].dir));
							map[i][j].init();
						}
					}
				}
				
			}
			
			
			//Output
			int answer = 0;
			while(!q.isEmpty()) answer += q.poll().num;
			sb.append('#').append(t).append(' ').append(answer).append('\n');
		}
		System.out.print(sb);
	}

}
