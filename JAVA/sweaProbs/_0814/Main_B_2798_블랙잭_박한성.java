package _0814;

/**
 * 메모리 : 14136
 * 실행시간 : 104
 * 
 * 3중 반복문으로 3가지 숫자 고르기
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_B_2798_블랙잭_박한성 {

	public static void main(String[] args) throws IOException {
		int arr[] = new int[100];
		
		//input
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		StringTokenizer st2 = new StringTokenizer(br.readLine());
		for(int i = 0;i < N;i++) arr[i] = Integer.parseInt(st2.nextToken());
		
		//pick 3 and update
		int answer = 0;
		int cur = 0;
		for(int i = 0;i < N;i++) {
			cur = arr[i];
			for(int j = i+1;j < N;j++) {
				cur += arr[j];
				for(int k = j+1;k < N;k++) {
					cur += arr[k];
					if(cur <= M && answer < cur) answer = cur;
					if(cur == M) {
						System.out.println(cur);
						return;
					}
					cur -= arr[k];
				}
				cur -= arr[j];
			}
		}
		
		//output
		System.out.println(answer);

	}

}
