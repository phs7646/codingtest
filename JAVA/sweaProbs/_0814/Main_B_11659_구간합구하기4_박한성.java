package _0814;

/**
 * 메모리 : 55104
 * 실행 시간 : 540
 * arr[i]에 sum(1..i)를 저장하고
 * arr[b] - arr[a-1] 하면 sum(a..b)가 계산됨
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_B_11659_구간합구하기4_박한성 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int arr[] = new int[N+1];
		StringTokenizer st2 = new StringTokenizer(br.readLine());
		for(int i = 1;i <= N;i++) {
			arr[i] = arr[i-1] + Integer.parseInt(st2.nextToken());
		}
		for(int i = 0;i < M;i++) {
			StringTokenizer st3 = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st3.nextToken());
			int b = Integer.parseInt(st3.nextToken());
			sb.append(arr[b]-arr[a-1]).append('\n');
		}
		System.out.println(sb.toString());
	}

}
