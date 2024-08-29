package _0829;

/**
 * 메모리 : 37024
 * 실행 시간 : 416
 * 인접리스트를 활용한 dfs
 */

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main_B_13023_ABCDE_박한성 {
	static int N;
	static List<Integer>[] adj;
	static boolean visited[];
	static void longestPath(int p, int depth) {
		if(depth >= 5) {
			System.out.println(1);
			System.exit(0);
		}
		for(int next : adj[p]) {
			if(visited[next]) continue;
			visited[next] = true;
			longestPath(next, depth+1);
			visited[next] = false;
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		int M = sc.nextInt();
		adj = new List[N];
		for(int i = 0;i < N;i++) adj[i] = new ArrayList<Integer>();
		for(int i = 0;i < M;i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			adj[a].add(b);
			adj[b].add(a);
		}
		visited= new boolean[N];
		for(int i = 0;i < N;i++) {
			visited[i] = true;
			longestPath(i,1);
			visited[i] = false;
		}
		System.out.println(0);
	}

}
