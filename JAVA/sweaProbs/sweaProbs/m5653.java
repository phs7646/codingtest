package sweaProbs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class m5653 {
	static class Point {
		int i,j;
		Point(int x,int y) {i=x;j=y;}
	}
	final static int SIZE = 800;
	final static int OFFSET = 400;
	final static int QSIZE = 12;
	static int map[][];
	static PriorityQueue<Point> pq[];
	static int movei[] = {0,0,1,-1};
	static int movej[] = {1,-1,0,0};
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		//generate reader writer
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		pq = new PriorityQueue[QSIZE];
		for(int i = 0;i < QSIZE;i++) pq[i] = new PriorityQueue<>((a,b) -> {
			int x1 = map[a.i][a.j];
			int x2 = map[b.i][b.j];
			return Integer.compare(x2, x1);
		});
		
		int T = Integer.parseInt(br.readLine().trim());
		for(int t = 1;t <= T;t++) {
			int answer = 0;
			//initialize
			for(int i = 0;i < QSIZE;i++) pq[i].clear();
			map = new int[SIZE][SIZE];
			
			//get input
			StringTokenizer st = new StringTokenizer(br.readLine().trim());
			int N = Integer.parseInt(st.nextToken());
			int M = Integer.parseInt(st.nextToken());
			int K = Integer.parseInt(st.nextToken());
			for(int i = 0;i < N;i++) {
				int j = 0;
				for(String s : br.readLine().trim().split(" ")) {
					int x = Integer.parseInt(s);
					if(x == 0) {
						j++;
						continue;
					}
					pq[x%QSIZE].add(new Point(OFFSET+i,OFFSET+j));
					if(2*x > K) answer++;
					map[OFFSET+i][OFFSET+j++] = x;
				}
			}
			//logic
			for(int day = 1;day < K;day++) {
				int cur_target = day%QSIZE;
				while(!pq[cur_target].isEmpty()) {
					Point p = pq[cur_target].poll();
					int x = map[p.i][p.j];
					for(int d = 0;d < 4;d++) {
						int newi = p.i + movei[d];
						int newj = p.j + movej[d];
						if(map[newi][newj] > 0) continue; //already occupied
						//occupy
						map[newi][newj] = x;
						if(day + 1 + 2 * x > K) answer++;
						pq[(day+x+1)%QSIZE].add(new Point(newi,newj));
					}
				}
			}
			sb.append('#').append(t).append(' ').append(answer).append('\n');
		}
		System.out.println(sb.toString());
	}
}
