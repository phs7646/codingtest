package etc;

import java.util.Scanner;

public class permutation_Q {
	static int N;	//arr의 크기(요소의 개수
	static int R;	//뽑을 개수
	static StringBuilder sb;
	static char[] cur;
	static int[] arr;
	static boolean[] visited;
	static int count = 0;
	static void dfs(int pos) {
		if(pos == R) {
			sb.append(cur);
			count++;
			return;
		}
		for(int i = 0;i < N;i++) {
			if(visited[i]) continue;
			visited[i] = true;
			cur[pos*2] = (char) (arr[i]+'0');
			dfs(pos+1);
			visited[i] = false;
		}
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		N = sc.nextInt();
		R = sc.nextInt();
		
		arr = new int[N];
		
		for(int i=0; i<N; i++) arr[i] = sc.nextInt();
		
		cur = new char[2*R];
		cur[2*R-1] = '\n';
		visited = new boolean[N];
		sb = new StringBuilder();
		dfs(0);
		System.out.print(sb.toString());
		System.out.println(count);
		
	}


	
}