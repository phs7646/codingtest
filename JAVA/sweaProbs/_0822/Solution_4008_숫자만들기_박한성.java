package _0822;

/**
 * 메모리 : 19172
 * 실행 시간 : 128
 * dfs
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_4008_숫자만들기_박한성 {

	static int count[] = new int[4];
	static long array[];
	static long min;
	static long max;
	static long cur;
	static void dfs(int pos) {
		if(pos == array.length) {
			min = Math.min(min, cur);
			max = Math.max(max, cur);
			return;
		}
		//pos위치를 계산
		for(int op = 0;op < 4;op++) {
			if(count[op] == 0) continue;
			count[op]--;
			long backup = cur;
			if(op == 0) cur += array[pos];
			else if(op == 1) cur -= array[pos];
			else if(op == 2) cur *= array[pos];
			else cur /= array[pos];
			dfs(pos+1);
			count[op]++;
			cur = backup;
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine().trim());
		for(int t = 1;t <= T;t++) {
			//input
			int N = Integer.parseInt(br.readLine().trim());
			StringTokenizer st = new StringTokenizer(br.readLine().trim());
			for(int i = 0;i < 4;i++) count[i] = Integer.parseInt(st.nextToken());
			array = new long[N];
			st = new StringTokenizer(br.readLine().trim());
			for(int i = 0;i < N;i++) array[i] = Integer.parseInt(st.nextToken());
			
			//initialize
			cur = array[0];
			min = Long.MAX_VALUE;
			max = Long.MIN_VALUE;
			
			dfs(1);
			
			sb.append('#').append(t).append(' ').append(max-min).append('\n');
		}
		System.out.print(sb);
	}

}
