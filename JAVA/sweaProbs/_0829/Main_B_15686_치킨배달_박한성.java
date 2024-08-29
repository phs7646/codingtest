package _0829;

/**
 * 메모리 : 21788
 * 실행 시간 : 200
 * 전처리와 비트마스킹
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main_B_15686_치킨배달_박한성 {
	static int nextBit(int bit) {
	    int x = bit & -bit;           
	    int y = bit + x;      
	    bit = ((bit & ~y) / x >> 1) | y;
	    return bit;
	}
	static int N,M;
	static int nC,nH;
	static int dist[][];
	static class Point{
		int y,x;
		Point(int a,int b) {y = a; x = b;}
		int dist(Point p2) {
			return Math.abs(y-p2.y) + Math.abs(x-p2.x);
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine().trim());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		List<Point> chickens = new ArrayList<>();
		List<Point> homes = new ArrayList<>();
		for(int i = 0;i < N;i++) {
			st = new StringTokenizer(br.readLine().trim());
			for(int j = 0;j < N;j++) {
				int a = Integer.parseInt(st.nextToken());
				if(a == 2) chickens.add(new Point(i,j));
				else if(a == 1) homes.add(new Point(i,j));
			}
		}
		nC = chickens.size();
		nH = homes.size();
		dist = new int[nC][nH];
		for(int i = 0;i < nC;i++) {
			for(int j = 0;j < nH;j++) {
				dist[i][j] = chickens.get(i).dist(homes.get(j));
			}
		}
		//dist에서 M개의 행을 골라 각 열의 최솟값 의 합을 최소로 해야함
		int bit = (1<<M)-1;
		int answer = Integer.MAX_VALUE;
		while(bit < (1<<nC)) {
			List<Integer> picked = new ArrayList<>();
			for(int i = 0;i < nC;i++) if((bit & (1<<i)) > 0) picked.add(i);
			int cur = 0;
			for(int j = 0;j < nH;j++) {
				int min = Integer.MAX_VALUE;
				for(int chick : picked) {
					min = Math.min(min, dist[chick][j]);
				}
				cur += min;
			}
			answer = Math.min(answer,cur);
			bit = nextBit(bit);
		}
		System.out.println(answer);
		
	}

}
