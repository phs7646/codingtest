package _0904;

/**
 * 메모리 : 35916
 * 실행 시간 : 232
 * 거리를 전처리 하고 완전탐색
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Solution_2117_홈방범서비스_박한성 {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine().trim());
		for(int t = 1;t <= T;t++) {
			StringTokenizer st = new StringTokenizer(br.readLine().trim());
			int N = Integer.parseInt(st.nextToken());
			int M = Integer.parseInt(st.nextToken());
			List<int []> homes = new ArrayList<>();
			for(int i = 0;i < N;i++) {
				st = new StringTokenizer(br.readLine().trim());
				for(int j = 0; j< N;j++) {
					int a = Integer.parseInt(st.nextToken());
					if(a==1) homes.add(new int[] {i,j});
				}
			}
			//pre process
			int dist[][][] = new int[N][N][homes.size()];
			for(int i = 0;i < N;i++) {
				for(int j = 0;j < N;j++) {
					for(int k = 0;k < homes.size();k++) {
						int y[] = homes.get(k);
						dist[i][j][k] = Math.abs(i-y[0]) + Math.abs(j-y[1]);
					}
				}
			}
			
			//영역 K : 절댓값 차이가 K-1이하
			int answer = -1;
			int possib = M * homes.size();
			for(int K = N<<1; K >= 1; K--) {
				int cost = K*K + (K-1)*(K-1);
				if(possib < cost) continue;
				int least = cost%M==0?cost/M : cost/M + 1;
				for(int i = 0;i < N;i++) {
					for(int j = 0;j < N;j++) {
						int cur = 0;
						for(int k = 0;k < homes.size();k++) {
							if(dist[i][j][k] <= K-1) cur++;
						}
//						System.out.println(i + "," + j + "," + K + "에서 " + cur);
						if(cur >= least) {
							answer = Math.max(answer, cur);
						}
					}
				}
				if(answer != -1) {
					sb.append('#').append(t).append(' ').append(answer).append('\n');
					break;
				}
			}
		}
		System.out.print(sb);
	}

}
