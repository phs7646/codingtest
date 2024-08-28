package _0828;

/**
 * 메모리 : 20,448 
 * 실행시간 : 126
 * bfs
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution_1238_Contact_인접행렬_박한성 {
	static final int MAX = 100;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		for(int t= 1;t <= 10;t++) {
			//input
			StringTokenizer st = new StringTokenizer(br.readLine().trim());
			int N = Integer.parseInt(st.nextToken());
			int S = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine().trim());
			boolean adj[][] = new boolean[MAX+1][MAX+1];
			for(int i = 0;i < (N>>1);i++) {
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				adj[a][b] = true;
			}
			
			//start
			Queue<Integer> q = new LinkedList<>();
			boolean visited[] = new boolean[MAX+1];
			q.add(S);
			int answer = S;
			while(!q.isEmpty()) {
				answer = 0;
				int qSize = q.size();
				for(int i = 0;i < qSize;i++) {
					int cur = q.poll();
					answer = Math.max(answer,cur);
					for(int next = 1;next <= MAX;next++) {
						if(visited[next] || !adj[cur][next]) continue;
						visited[next] = true;
						q.add(next);
					}
				}
			}
			sb.append('#').append(t).append(' ').append(answer).append('\n');
		}
		System.out.print(sb);
	}

}
