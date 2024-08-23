package _0822;

/**
 * 메모리 : 30384
 * 실행 시간 : 165
 * 각 숫자가 배정된 방을 기록하고,
 * 지금 숫자에서 다음 숫자로 갈 수 있는지 abs(i1-i2)+abs(j1-j2)로 계산한다
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_1861_정사각형방_박한성 {
	static class Point {
		int i,j;
		Point(int a,int b) {i = a; j = b;}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine().trim());
		for(int t = 1;t <= T;t++) {
			int N = Integer.parseInt(br.readLine().trim());
			Point map[] = new Point[N*N+1];
			for(int i = 0;i < N;i++) {
				StringTokenizer st = new StringTokenizer(br.readLine().trim());
				for(int j = 0;j < N;j++) {
					int p = Integer.parseInt(st.nextToken());
					map[p] = new Point(i,j);
				}
			}
			int answer_start = 1;
			int answer_dist = 1;
			int current_dist = 1;
			for(int k = 2;k <= N*N;k++) {
				Point prev = map[k-1];
				Point cur = map[k];
				if(Math.abs(cur.i-prev.i) + Math.abs(cur.j-prev.j) == 1) {
					current_dist++;
				} else {
					if(answer_dist < current_dist) {
						answer_dist = current_dist;
						answer_start = k - current_dist;
					}
					current_dist = 1;
				}
			}
			if(answer_dist < current_dist) {
				answer_dist = current_dist;
			}
			sb.append('#').append(t).append(' ').append(answer_start).append(' ').append(answer_dist).append('\n');
		}
		System.out.print(sb);
	}

}
