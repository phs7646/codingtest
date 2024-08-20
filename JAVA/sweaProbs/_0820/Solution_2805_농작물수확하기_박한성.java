package _0820;

/**
 * 메모리 : 19468
 * 실행 시간 : 116
 * 구현
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution_2805_농작물수확하기_박한성 {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine().trim());
		for(int t = 1;t <= T;t++) {
			int N = Integer.parseInt(br.readLine().trim());
			int center = N/2;
			int answer = 0;
			for(int i = 0;i < N;i++) {
				String s = br.readLine().trim();
				for(int j = 0;j < N;j++) {
					if(Math.abs(i-center) + Math.abs(j-center) <= center) answer += s.charAt(j) - '0';
				}
			}
			sb.append('#').append(t).append(' ').append(answer).append('\n');
		}
		System.out.print(sb);
	}

}
