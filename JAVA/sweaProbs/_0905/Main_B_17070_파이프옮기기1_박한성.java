package _0905;

/**
 * 메모리 : 14356
 * 실행 시간 : 112
 * DP (i,j,type)
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main_B_17070_파이프옮기기1_박한성 {
	
	static int N;
	static boolean wall[][];
	
	static boolean isValid(int i,int j) {
		return (i>=0 && i < N && j >= 0 && j < N && !wall[i][j]);
	}
	static boolean isEnd(int i,int j,int type) {
		if(type == 0 && i == N-1 && j == N-2) return true;
		else if(type == 1 && i == N-2 && j == N-2) return true;
		else if(type == 2 && i == N-2 && j == N-1) return true;
		else return false;
	}
	static boolean isValidPipe(int i,int j,int type) {
		if(!isValid(i,j)) return false;
		if(type == 0) {
			return isValid(i,j+1);
		} else if(type == 2) {
			return isValid(i+1,j);
		} else {
			if(isValid(i,j+1) && isValid(i+1,j) && isValid(i+1,j+1)) return true;
			else return false;
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		//input
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		wall = new boolean[N][N];
		for(int i = 0;i < N;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine().trim());
			for(int j = 0;j < N;j++) {
				int n = Integer.parseInt(st.nextToken());
				if(n == 1) wall[i][j] = true;
			}
		}
		int dp[][][] = new int[N][N][3];
		dp[0][0][0] = 1;
		
		int answer = 0;
		for(int i = 0;i < N;i++) {
			for(int j = 0;j < N;j++) {
				for(int type = 0;type < 3;type++) {
					if(dp[i][j][type] == 0) continue;
					if(isEnd(i,j,type)) {
						answer += dp[i][j][type];
						continue;
					}
					//make next case
					List<int[]> next = new ArrayList<>();
					if(type == 0) {
						next.add(new int[] {i,j+1,0});
						next.add(new int[] {i,j+1,1});
					} else if(type == 1) {
						next.add(new int[] {i+1,j+1,0});
						next.add(new int[] {i+1,j+1,1});
						next.add(new int[] {i+1,j+1,2});
					} else if(type == 2) {
						next.add(new int[] {i+1,j,2});
						next.add(new int[] {i+1,j,1});
					}
					for(int[] c : next) {
						if(isValidPipe(c[0],c[1],c[2])) {
							dp[c[0]][c[1]][c[2]] += dp[i][j][type];
						}
					}
				}
			}
		}
		System.out.println(answer);
		
		
	}
}
