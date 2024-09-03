package _0903;

/**
 * 메모리 : 20576
 * 실행 시간 : 134
 * 전처리와 완전 탐색
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Solution_2115_벌꿀채취_박한성 {
	static int N,M,C;
	static int map[][];
	static int maxProfit(int y, int x) {
		int ret = 0;
		for(int bit = 1; bit < (1<<M);bit++) {
			int prof = 0;
			int sum = 0;
			for(int i = 0;i < M;i++) {
				if((bit&(1<<i))>0) {
					prof += map[y][x+i] * map[y][x+i];
					sum += map[y][x+i];
				}
			}
			if(sum <= C) ret = Math.max(ret, prof);
		}
		return ret;
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine().trim());
		for(int t = 1;t <= T;t++) {
			//input
			StringTokenizer st = new StringTokenizer(br.readLine().trim());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			C = Integer.parseInt(st.nextToken());
			map = new int[N][N];
			for(int i = 0;i < N;i++) {
				st = new StringTokenizer(br.readLine().trim());
				for(int j = 0;j < N;j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			//preprocess
			int maxProf[][] = new int[N][N-M+1];
			for(int i = 0;i < N;i++) {
				for(int j = 0;j <= N-M;j++) {
					maxProf[i][j] = maxProfit(i,j);
				}
			}
			
			//brute force
			int answer = 0;
			//case - pick two different line
			List<Integer> lineMax = new ArrayList<>();
			for(int i = 0;i < N;i++) {
				int cur = 0;
				for(int j = 0;j <= N-M;j++) cur = Math.max(cur, maxProf[i][j]);
				lineMax.add(cur);
			}
			lineMax.sort(null);
			answer = lineMax.get(N-1) + lineMax.get(N-2); //pick best two line
			
			//case - pick two in one line
			if(N >= 2*M) {
				for(int i = 0;i < N;i++) {
					int cur = 0;
					//pick a,b that b-a >= M
					for(int a = 0;a <= N-2*M;a++) {
						for(int b = a+M; b <= N-M;b++) {
							cur = Math.max(cur, maxProf[i][a] + maxProf[i][b]);
						}
					}
					answer = Math.max(answer, cur);
				}
			}
			sb.append('#').append(t).append(' ').append(answer).append('\n');
		}
		System.out.print(sb);
	}
}
