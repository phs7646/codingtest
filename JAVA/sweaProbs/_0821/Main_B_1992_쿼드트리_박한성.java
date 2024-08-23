package _0821;

/**
 * 메모리 : 17936
 * 실행 시간 : 156
 * 구간을 분할해가며 해당 구간에 대한 문자열을 리턴
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main_B_1992_쿼드트리_박한성 {
	
	static String[] map;
	
	static String dfs(int a,int b, int l) {
		int sum = 0;
		for(int i = a;i < a+l;i++) {
			for(int j = b;j < b+l;j++) {
				sum += map[i].charAt(j)-'0';
			}
		}
		if(sum == 0) return "0";
		else if(sum == l*l) return "1";
		
		l >>= 1;
		return "(" + dfs(a,b,l) + dfs(a,b+l,l) + dfs(a+l,b,l) + dfs(a+l,b+l,l) + ")";
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine().trim());
		map = new String[N];
		for(int i = 0;i < N;i++) map[i] = br.readLine().trim();
		System.out.println(dfs(0,0,N));
	}

}
