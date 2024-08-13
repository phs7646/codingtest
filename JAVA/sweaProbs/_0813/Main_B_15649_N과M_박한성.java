package _0813;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
/*
 * 메모리 : 23088
 * 실행 시간 : 224
 * 
 * 2M 길이의 char 배열을 미리 만들고
 * dfs로 2*pos 자리에 숫자를 정한다
 */
public class Main_B_15649_N과M_박한성 {
	static StringBuilder sb;
	static int N,M;
	static boolean visited[] = new boolean[10];
	static char cur[];
	static void dfs(int pos) {
		if(pos == M) {
			sb.append(cur).append('\n');
			return;
		}
		for(int i = 1;i <= N;i++) {
			if(visited[i]) continue;
			visited[i] = true;
			cur[2*pos] = (char) ('0'+i);
			dfs(pos+1);
			visited[i] = false;
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		sb = new StringBuilder();
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		cur = new char[2*M];
		for(int i = 0;i < M;i++) {
			cur[2*i+1] = ' ';
		}
		dfs(0);
		System.out.println(sb.toString());
	}

}