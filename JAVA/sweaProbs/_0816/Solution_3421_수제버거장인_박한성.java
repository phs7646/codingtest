package _0816;

/**
 * 메모리 : 96688
 * 실행 시간 : 793
 * 비트마스킹
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Solution_3421_수제버거장인_박한성 {
	static StringBuilder sb;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine().trim());
		for(int t = 1;t <= T;t++) {
			StringTokenizer st = new StringTokenizer(br.readLine().trim());
			int N = Integer.parseInt(st.nextToken());
			int M = Integer.parseInt(st.nextToken());
			if(M == 0 || N == 1) {
				sb.append('#').append(t).append(' ').append(1<<N).append('\n');
				continue;
			}
			Set<Integer> set = new HashSet<>();
			for(int i = 0;i < M;i++) {
				st = new StringTokenizer(br.readLine().trim());
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				set.add(((1 << (a-1)) | (1 << (b-1))));
			}
			int max_bit = 1 << N;
			int answer = 0;
			for(int bit = 0;bit < max_bit;bit++) {
				boolean flag = true;
				for(int b : set) if((bit & b) == b) {
					flag = false;
					break;
				}
				if(flag) answer++;
			}
			sb.append('#').append(t).append(' ').append(answer).append('\n');
		}
		System.out.print(sb);
	}

}
