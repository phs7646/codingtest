package _0813;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution_1954_달팽이숫자_박한성 {

	static int arr[][] = new int[10][10];
	static int movei[] = {0,1,0,-1};
	static int movej[] = {1,0,-1,0};
	
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine().trim());
		for(int t = 1;t <= T;t++) {
			sb.append('#').append(t).append('\n');
			int N = Integer.parseInt(br.readLine().trim());
			int i = 0;
			int j = 0;
			int num = 1;
			for(int len = N-1;len > 0;len-=2) {
				for(int d = 0;d < 4;d++) {
					//d방향으로 len만큼 움직이기
					for(int l = 0;l < len;l++) {
						arr[i][j] = num++;
						i += movei[d];
						j += movej[d];
					}
				}
				i++;
				j++;
			}
			if((N&1) == 1) arr[i][j] = num;
			for(int a = 0;a < N;a++) {
				for(int b = 0;b < N;b++) sb.append(arr[a][b]).append(' ');
				sb.append('\n');
			}
		}
		System.out.println(sb.toString());
	}
}
