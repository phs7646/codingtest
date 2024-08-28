package _0828;

/**
 * 메모리 : 100300
 * 실행 시간 : 414
 * 서로소 집합 구현
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_3289_서로소집합_박한성 {
	static int N,M;
	static int root[]; //0 : self
	
	static int findroot(int key) {
		if(root[key] == 0) return key;
		return root[key] = findroot(root[key]);
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int T = Integer.parseInt(br.readLine().trim());
		for(int t = 1;t <= T;t++) {
			sb.append('#').append(t).append(' ');
			StringTokenizer st = new StringTokenizer(br.readLine().trim());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			root = new int[N+1];
			for(int m = 0;m < M;m++) {
				st = new StringTokenizer(br.readLine().trim());
				int q = Integer.parseInt(st.nextToken());
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				if(q == 0) {
					int roota = findroot(a);
					int rootb = findroot(b);
					if(roota != rootb) {
						root[rootb] = roota;
					}
				} else {
					if(findroot(a) == findroot(b)) sb.append('1');
					else sb.append('0');
				}
			}
			sb.append('\n');
		}
		System.out.print(sb);
	}

}
