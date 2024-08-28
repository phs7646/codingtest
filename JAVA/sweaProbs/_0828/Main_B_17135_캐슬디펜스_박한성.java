package _0828;

/**
 * 메모리 : 19356
 * 실행 시간 : 148
 * 비트마스킹을 이용한 완전탐색
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main_B_17135_캐슬디펜스_박한성 {
	static int nextBit(int bit) {
	    int x = bit & -bit;           
	    int y = bit + x;      
	    bit = ((bit & ~y) / x >> 1) | y;
	    return bit;
	}
	static int[] getPos(int bit,int M) {
		int[] ret = new int[3];
		int count = 0;
		for(int i = 0;i < M;i++) if((bit & (1<<i))>0) ret[count++] = i;
		return ret;
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int D = Integer.parseInt(st.nextToken());
		int map[][] = new int[N][M];
		for(int i = 0;i < N;i++) {
			st = new StringTokenizer(br.readLine().trim());
			for(int j = 0;j < M;j++) map[i][j] = Integer.parseInt(st.nextToken());
		}
		
		int bit = 7;
		int answer = 0;
		while(bit < (1<<M)) {
			boolean killed[][] = new boolean[N][M];
			int pos[] = getPos(bit,M);
			int cur = 0;
			for(int day = 0;day < N;day++) {
				//현재 행 : N-day
				List<int[]> toKill = new ArrayList<>();
				for(int ranger = 0;ranger < 3;ranger++) {
					//공격 대상 정하기
					int targeti = -1, targetj = -1;
					int targetdist = -1;
					for(int j = 0;j < M;j++) {
						//각 열의 맨 앞만 볼것임
						for(int i = N-day-1;i >= 0;i--) {
							if(map[i][j] == 1 && !killed[i][j]) {
								//found target
								int dist = Math.abs(i-(N-day)) + Math.abs(j-pos[ranger]);
								if(targetdist == -1 || targetdist > dist || targetj > j) {
									targetdist = dist;
									targeti = i;
									targetj = j;
								}
								break;
							}
						}
					}
					//타겟 설정 완료
					if(targetdist != -1 && targetdist <= D) toKill.add(new int[] {targeti,targetj});
				}
				//쏘기
				for(int[] target : toKill) {
					if(!killed[target[0]][target[1]]) {
						cur++;
						killed[target[0]][target[1]] = true;
					}
				}
			}
			answer = Math.max(answer, cur);
			bit = nextBit(bit);
		}
		System.out.println(answer);
	}

}
