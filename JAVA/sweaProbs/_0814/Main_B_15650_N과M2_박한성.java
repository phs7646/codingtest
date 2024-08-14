package _0814;

/**
 * 메모리 : 14124
 * 실행 시간 : 100
 * 이전에 고른 것 보다 더 큰거로 고르기
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_B_15650_N과M2_박한성 {

	static StringBuilder sb;
	static int N,M;
	static char cur[];
	static void dfs(int pos, int last) {
		if(pos == M) {
			sb.append(cur).append('\n');
			return;
		}
		for(int i = last+1;i <= N - (M-pos-1);i++) {
			cur[2*pos] = (char) ('0'+i);
			dfs(pos+1,i);
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
		dfs(0,0);
		System.out.println(sb.toString());
	}


}
