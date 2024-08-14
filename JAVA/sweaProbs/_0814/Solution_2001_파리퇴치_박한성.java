package _0814;

/**
 * 메모리 : 20528
 * 실행 시간 : 120
 * 
 * accum[i][j] : 0,0 -> i,j 까지 사각형의 합
 * 이 때 i,j를 오른쪽 아래 점으로 하는 크기가 M인 사각형의 합은 포함과 배제의 원리에 따라
 * sum(i,j) = accum[i][j] - accum[i-M][j] - accum[i][j-M] + accum[i-M][j-M]
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_2001_파리퇴치_박한성 {
	
	static int arr[][] = new int[15][15];
	static int accum[][] = new int[15][15];
	
	public static void main(String[] args) throws IOException {
		
		//br,sb
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int T = Integer.parseInt(br.readLine());
		for(int t = 1;t <= T;t++) {
			
			//input N,M
			StringTokenizer st2 = new StringTokenizer(br.readLine());
			int N = Integer.parseInt(st2.nextToken());
			int M = Integer.parseInt(st2.nextToken());
			
			//input arr
			for(int i = 0;i < N;i++) {
				int j = 0;
				for(String s : br.readLine().trim().split(" ")) {
					arr[i][j++] = Integer.parseInt(s);
				}
			}
			//build accum
			accum[0][0] = arr[0][0];
			//build i = 0
			for(int j = 1;j < N;j++) accum[0][j] = accum[0][j-1] + arr[0][j];
			//build j = 0;
			for(int i = 1;i < N;i++) accum[i][0] = accum[i-1][0] + arr[i][0];
			//build remain
			for(int i = 1;i < N;i++) {
				for(int j = 1;j < N;j++) {
					accum[i][j] = arr[i][j] + accum[i-1][j] + accum[i][j-1] - accum[i-1][j-1];
				}
			}
			
			//calculate
			int answer = 0;
			for(int i = M-1;i < N;i++) {
				for(int j = M-1;j < N;j++) {
					//i,j를 오른쪽 아래로 하는 경우
					//accum[i][j] - accum[i-M][j] - accum[i][j-M] + accum[i-M][j-M]
					int cur = accum[i][j];
					if(i >= M) cur -= accum[i-M][j];
					if(j >= M) cur -= accum[i][j-M];
					if(i >= M && j >= M) cur += accum[i-M][j-M];
					answer = Math.max(answer,cur);
				}
			}
			
			//output
			sb.append('#').append(t).append(' ').append(answer).append('\n');
		}
		System.out.println(sb.toString());
	}

}
