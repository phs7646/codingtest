package _0827;

/**
 * 메모리 : 95144
 * 실행 시간 : 441
 * BFS 완탐
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution_7733_치즈도둑_박한성 {

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		int dy[] = {1,-1,0,0};
		int dx[] = {0,0,-1,1};
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine().trim());
		for(int t = 1;t <= T;t++) {
			int N = Integer.parseInt(br.readLine().trim());
			int[][] map = new int[N][N];
			for(int i = 0;i < N;i++) {
				StringTokenizer st = new StringTokenizer(br.readLine().trim());
				for(int j = 0;j < N;j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			int answer = 1;
			//logic
			for(int day = 1;day < 100;day++) {
				//day이하의 치즈는 갉아먹힘
				int cur_answer = 0;
				boolean visited[][] = new boolean[N][N];
				for(int i = 0;i < N;i++) {
					for(int j = 0;j < N;j++) {
						if(visited[i][j]) continue;
						if(map[i][j] <= day) continue;
						cur_answer++;
						Queue<int[]> q= new LinkedList<>();
						visited[i][j] = true;
						q.add(new int[] {i,j});
						while(!q.isEmpty()) {
							int[] cur = q.poll();
							for(int d = 0;d < 4;d++) {
								int ni = cur[0] + dy[d];
								int nj = cur[1] + dx[d];
								if(0 <= ni && ni < N && 0 <= nj && nj < N && !visited[ni][nj] && map[ni][nj] > day) {
									visited[ni][nj] = true;
									q.add(new int[] {ni,nj});
								}
							}
						}
					}
				}
				answer = Math.max(answer, cur_answer);
			}
			//output
			sb.append('#').append(t).append(' ').append(answer).append('\n');
		}	
		System.out.print(sb);
	}

}
