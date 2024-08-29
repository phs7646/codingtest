package _0829;

/**
 * 메모리 : 195,712
 * 실행 시간 :  6698 
 */

import java.util.Arrays;
import java.util.Scanner;

public class Solution_3124_최소스패닝트리_박한성 {

	static int V;
	static int[] parents;

	static int findSet(int a) {
		if (parents[a] < 0)
			return a;
		return parents[a] = findSet(parents[a]);
	}

	static boolean union(int a, int b) {
		int aRoot = findSet(a);
		int bRoot = findSet(b);
		if (aRoot == bRoot)
			return false;

		parents[aRoot] += parents[bRoot]; 
		parents[bRoot] = aRoot;
		return true;
	}

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		int T = sc.nextInt();
		for (int t = 1; t <= T; t++) {
			V = sc.nextInt();
			parents = new int[V];
			for (int i = 0; i < V; i++) {
				parents[i] = -1;
			}
			
			int E = sc.nextInt();
			Edge[] edges = new Edge[E];
			for (int i = 0; i < E; i++) {
				edges[i] = new Edge(sc.nextInt()-1, sc.nextInt()-1, sc.nextInt());
			}
			Arrays.sort(edges);
			
			int cnt = 0;
			long cost = 0;
			for (Edge edge : edges) {
				if (union(edge.start, edge.end)) {
					cost += edge.weight;
					if (++cnt == V - 1)
						break;
				}
			}
			sb.append('#').append(t).append(' ').append(cost).append('\n');
		}
		System.out.print(sb);
	}

	static class Edge implements Comparable<Edge> {
		int start, end, weight;

		public Edge(int start, int end, int weight) {
			super();
			this.start = start;
			this.end = end;
			this.weight = weight;
		}

		@Override
		public int compareTo(Edge o) {
			return Integer.compare(this.weight, o.weight);
		}
	}

}