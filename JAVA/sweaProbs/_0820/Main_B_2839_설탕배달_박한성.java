package _0820;

/**
 * 메모리 : 17692
 * 실행 시간 : 172
 * 5kg을 최대한 많이 들기
 */

import java.util.Scanner;

public class Main_B_2839_설탕배달_박한성 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		for(int i = N/5;i >= 0;i--) {
			int remain = N - i*5;
			if(remain % 3 == 0) {
				System.out.println((i+remain/3));
				return;
			}
		}
		System.out.println(-1);
	}

}
