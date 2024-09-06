package _0906;

/**
 * 메모리 : 62448
 * 실행 시간 : 512
 * bfs (i,j,k)
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main_B_1600_말이되고픈원숭이_박한성 {
	static int K,N,M;
	static int map[][];
	
	static int dy[] = {1,-1,0,0};
	static int dx[] = {0,0,1,-1};
	
	static int jumpy[] = {-2,-1,1,2,2,1,-1,-2};
	static int jumpx[] = {1,2,2,1,-1,-2,-2,-1};
	
	static boolean isValid(int i,int j) {
		return (i >= 0 && i < N && j >= 0 && j < M);
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		K = Integer.parseInt(br.readLine().trim());
		StringTokenizer st = new StringTokenizer(br.readLine().trim());
		M = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());
		map = new int[N][M];
		for(int i = 0;i < N;i++) {
			st = new StringTokenizer(br.readLine().trim());
			for(int j = 0;j < M;j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		//예외
		if(N==1 && M == 1) {
			System.out.println(0);
			System.exit(0);
		}
		//bfs + memo
		int visited[][] = new int[N][M];
		for(int i = 0;i < N;i++) for(int j = 0;j < M;j++) visited[i][j] = K+1;
		visited[0][0] = 0;
		Queue<int[]> q = new ArrayDeque<>();
		q.add(new int[] {0,0,0});
		int dist = 1;
		while(!q.isEmpty()) {
			int qSize = q.size();
			for(int qs = 0; qs < qSize;qs++) {
				int[] cur = q.poll();
				int i = cur[0]; int j = cur[1];
				if(cur[2] != visited[i][j]) continue;
				if(visited[i][j] < K) {
					//점프
					for(int jum = 0;jum < 8;jum++) {
						int ni = i + jumpy[jum];
						int nj = j + jumpx[jum];
						if(!isValid(ni,nj)) continue;
						if(map[ni][nj] == 1) continue;
						int newK = visited[i][j] + 1;
						if(visited[ni][nj] <= newK) continue;
						if(ni == N-1 && nj == M-1) {
							System.out.println(dist);
							System.exit(0);
						}
						visited[ni][nj] = newK;
						q.add(new int[] {ni,nj,newK});
					}
				}
				//단순이동
				for(int d = 0;d < 4;d++) {
					int ni = i + dy[d];
					int nj = j + dx[d];
					if(!isValid(ni,nj)) continue;
					if(map[ni][nj] == 1) continue;
					if(visited[ni][nj] <= visited[i][j]) continue;
					if(ni == N-1 && nj == M-1) {
						System.out.println(dist);
						System.exit(0);
					}
					visited[ni][nj] = visited[i][j];
					q.add(new int[] {ni,nj,visited[i][j]});
				}
			}
			dist++;
		}
		System.out.println(-1);
	}
}
