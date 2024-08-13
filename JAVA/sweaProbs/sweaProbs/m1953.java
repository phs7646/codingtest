package sweaProbs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class m1953 {
	
	static int map[][] = new int[50][50];
	static int N,M;
	static int movei[] = {-1,1,0,0}; //상하좌우
	static int movej[] = {0,0,-1,1};
	static boolean canMove[][] = {
			{false,false,false,false},
			{true,true,true,true},
			{true,true,false,false},
			{false,false,true,true},
			{true,false,false,true},
			{false,true,false,true},
			{false,true,true,false},
			{true,false,true,false}
	};
	static boolean visited[][] = new boolean[50][50];
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine().trim());
		for(int t = 1;t <= T;t++) {
			//get input
			StringTokenizer st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			int R = Integer.parseInt(st.nextToken());
			int C = Integer.parseInt(st.nextToken());
			int L = Integer.parseInt(st.nextToken());
			for(int i = 0;i < N;i++) {
				int j = 0;
				for(String s : br.readLine().trim().split(" ")) {
					visited[i][j] = false;
					map[i][j++] = Integer.parseInt(s);
				}
			}
			
			//logic
			int num_available = 1;
			visited[R][C] = true;
			Queue<Point> q = new LinkedList<>();
			q.add(new Point(R,C));
			for(int day = 1;day < L;day++) {
				int num = q.size();
				for(int k = 0;k < num;k++) {
					Point p = q.poll();
					for(int d = 0;d < 4;d++) {
						if(!canMove[map[p.x][p.y]][d]) continue;
						int nexti = p.x + movei[d];
						int nextj = p.y + movej[d];
						if(nexti < 0 || nexti >= N || nextj < 0 || nextj >= M) continue;
						if(visited[nexti][nextj]) continue;
						//상대편은 내가 가는걸 받을 수 있나..?
						//d방향으로 갈때 
						int oppoD = 0;
						switch(d) {
						case 0:
							oppoD=1;
							break;
						case 1:
							oppoD=0;
							break;
						case 2:
							oppoD=3;
							break;
						case 3:
							oppoD=2;
							break;
						}
						//상대는 oppoD 무브가 가능한가
						if(!canMove[map[nexti][nextj]][oppoD]) continue;
						if(map[nexti][nextj] == 0) continue;
						visited[nexti][nextj] = true;
						num_available++;
						if(day < L-1) q.add(new Point(nexti,nextj));
					}
				}
			}
			
			//debug
//			System.out.println();
//			for(int i = 0;i < N;i++) {
//				for(int j = 0;j < M;j++) {
//					if(visited[i][j]) System.out.print("1 ");
//					else System.out.print("0 ");
//				}
//				System.out.println();
//			}
			
			//output
			sb.append('#').append(t).append(' ').append(num_available).append('\n');
		}
		System.out.println(sb.toString());
	}
	static class Point {
		int x;
		int y;
		Point(int x,int y) {this.x=x;this.y=y;};
	}

}
