package _0821;

/**
 * 메모리 : 86,496
 * 실행 시간 : 589
 * 시키는대로 구현
 */

import java.util.Scanner;

public class Solution_6782_현주가좋아하는제곱근놀이_박한성 {
	
	static long dfs(long N) {
		if(N==2) return 0;
		double sq = Math.sqrt(N);
		long s = (long)(sq);
		if(s * s == N) return dfs(s) + 1;
		return dfs(s+1) + ((long)((s+1) * (s+1)) - N) + 1;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int t = 1;t <= T;t++) {
			long N = sc.nextLong();
			System.out.printf("#%d %d\n",t,dfs(N));
		}
	}

}
