package _0820;
/**
 * 메모리 : 101480
 * 실행 시간 : 818
 * O(N) 구현
 * 올라가고 있을 때랑 내려가고 있을 때를 구분,
 * 내려가다가 올라가는 지점에서 지난 구간의 경우의수 카운트
 */
import java.util.Scanner;

public class Solution_4796_의석이의우뚝선산_박한성 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		int T = sc.nextInt();
		for(int t = 1;t <= T;t++) {
			int N = sc.nextInt();
			int a = sc.nextInt();
			int b = sc.nextInt();
			
			int answer = 0;
			int increase = 0;
			int decrease = 0;
			boolean dir = true;
			if(a < b) {
				increase = 1;
				dir = true;
			} else {
				decrease = 1;
				dir = false;
			}
			int prev = b;
			for(int i = 2;i < N;i++) {
				int next = sc.nextInt();
				if(prev < next) {
					if(dir) {
						increase++;
					} else {
						//방향전환 발생 decrease -> increase
						answer += increase * decrease;
						dir = true;
						increase = 1;
						decrease = 0;
					}
				} else {
					if(!dir) {
						decrease++;
					} else {
						//방향전환 발생 decrease -> increase
						dir = false;
						decrease = 1;
					}
				}
				prev = next;
			}
			if(!dir) answer += increase * decrease ;
			sb.append('#').append(t).append(' ').append(answer).append('\n');
		}
		System.out.print(sb);
	}
}
