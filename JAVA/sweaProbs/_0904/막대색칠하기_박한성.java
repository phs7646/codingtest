package _0904;

import java.util.Scanner;

public class 막대색칠하기_박한성 {
	static long comb(int n,int k) {
		long ret = 1;
		for(int i = n; i > n-k;i--) ret *= i;
		for(int i = k; i >= 2;i--) ret /= i;
		return ret;
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long answer = 0;
		for(int i = 0;i <= (N>>1);i++) {
			//2짜리 막대 i개를 고르는 경우의 수
			answer += (1<<(N-2*i)) * comb(N-i,i);
		}
		System.out.println(answer);
	}
}
