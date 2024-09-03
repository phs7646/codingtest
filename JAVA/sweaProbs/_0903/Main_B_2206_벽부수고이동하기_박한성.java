package _0903;

/**
 * 메모리 : 104952
 * 시간 : 688
 * bfs
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main_B_2206_벽부수고이동하기_박한성 {
	
	public static void main(String[] args) throws IOException {
		int N,M;
		int dy[] = {-1,1,0,0};
		int dx[] = {0,0,-1,1};
		//input
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine().trim());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		boolean wall[][] = new boolean[N][M];
		for(int i = 0;i < N;i++) {
			String s = br.readLine().trim();
			for(int j = 0;j < M;j++) {
				if(s.charAt(j)=='1') wall[i][j] = true;
			}
		}
		if(N==1 && M==1) {
			System.out.println(1);
			return;
		}
		//dp table
		//int dp[][][] = new int[N][M][2];
		//dp[0][0][0] = 1;
		boolean visited[][][] = new boolean[N][M][2];
		Queue<int[]> q = new ArrayDeque<>();
		q.add(new int[] {0,0,0});
		int dist = 1;
		while(!q.isEmpty()) {
			int qSize = q.size();
			for(int qs = 0; qs < qSize;qs++) {
				int[] cur = q.poll();
				for(int d = 0;d < 4;d++) {
					int ny = cur[0] + dy[d];
					int nx = cur[1] + dx[d];
					if(0 > ny || ny >= N || 0 > nx || nx >= M) continue;
					if(!wall[ny][nx]) {
						//그대로 진행
						if(visited[ny][nx][cur[2]]) continue;
						visited[ny][nx][cur[2]] = true;
						q.add(new int[] {ny,nx,cur[2]});
					} else {
						//벽이 있음
						if(cur[2] == 1) continue;
						if(visited[ny][nx][1]) continue;
						visited[ny][nx][1] = true;
						q.add(new int[] {ny,nx,1});
					}
				}
			}
			dist++;
			if(visited[N-1][M-1][0] || visited[N-1][M-1][1]) {
				System.out.println(dist);
				return;
			}
		}
		System.out.println(-1);
	}
}
