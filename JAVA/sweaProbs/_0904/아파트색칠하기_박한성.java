package _0904;

public class 아파트색칠하기_박한성 {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[][] dp = new int[9][2];

		dp[1][0] = 1;
		dp[1][1] = 1;

		for (int i = 2; i <= 8; i++) {
			dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
			dp[i][1] = dp[i - 1][0];
		}

		System.out.println(dp[8][0] + dp[8][1]);
	}
}
