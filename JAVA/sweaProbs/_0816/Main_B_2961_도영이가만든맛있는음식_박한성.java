package _0816;

/**
 * 메모리 : 14188
 * 실행 시간 : 100
 * 비트마스킹
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_B_2961_도영이가만든맛있는음식_박한성 {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine().trim());
		int A[] = new int[N];
		int B[] = new int[N];
		for(int i = 0;i < N;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			A[i] = Integer.parseInt(st.nextToken());
			B[i] = Integer.parseInt(st.nextToken());
		}
		int max_bit = 1 << N;
		int answer = 1000000007;
		for(int bit = 1;bit < max_bit;bit++) {
	        int s = 1,b = 0;
	        for(int i = 0;i < N;i++) {	
	            if((bit & (1<<i)) != 0) {
	                s *= A[i];
	                b += B[i];
	            }
	        }
	        answer = Math.min(answer,Math.abs(s-b));
	    }
		System.out.println(answer);
	}

}
