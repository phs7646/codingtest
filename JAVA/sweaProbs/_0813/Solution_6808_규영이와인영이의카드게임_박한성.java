package _0813;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_6808_규영이와인영이의카드게임_박한성 {
	final static int N = 18;
	final static int hN = N>>1;
	final static int NINE_FACT = 362880;
	static boolean visited[] = new boolean[N+1];
	static int A[] = new int[hN];
	static int answer = 0;
	static int cur = 0;
	static void dfs(int pos) {
		if(pos == hN) {
			if(cur > 0) answer++;
			return;
		}
		
		//pos에서 뭘낼지 정하자
		for(int i = 1;i <= 18;i++) {
			if(visited[i]) continue;
			visited[i] = true;
			int tmp = cur;
			if(A[pos] < i) {
				cur += A[pos] + i;
			} else {
				cur -= A[pos] + i;
			}
			dfs(pos+1);
			cur = tmp;
			visited[i] = false;
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine().trim());
		for(int t = 1;t <= T;t++) {
			//initialize
			visited = new boolean[N+1];
			answer = 0;
			//get input
			StringTokenizer st = new StringTokenizer(br.readLine().trim());
			for(int i = 0;i < hN;i++) {
				int k = Integer.parseInt(st.nextToken());
				A[i] = k;
				visited[k] = true;
			}
			dfs(0);
			sb.append('#').append(t).append(' ').append(NINE_FACT-answer).append(' ').append(answer).append('\n');
		}
		System.out.println(sb.toString());
	}
}
