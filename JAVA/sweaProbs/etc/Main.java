package etc;

import java.io.IOException;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	static int INF = 100000000;

	public static void main(String[] args) throws NumberFormatException, IOException {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int K = sc.nextInt();
		if (N >= K) {
			System.out.println(N - K);
			return;
		}
		int dist[] = new int[K + 1];
		for (int i = 0; i <= K; i++)
			dist[i] = INF;
		int answer = INF;
		Queue<Integer> q = new ArrayDeque<>();
		int it = N;
		while(true) {
			if(it == K) {
				System.out.println(0);
				return;
			} else if(it > K) {
				answer = Math.min(answer, it-K);
				break;
			} else { //left < K
				dist[it] = 0;
				q.add(it);
				it <<= 1; //*2
				if(it == 0) break;
			}
		}
		while (!q.isEmpty()) {
			int cur = q.poll();
			if(dist[cur]+1 > answer) break;
			int d = dist[cur] + 1;
			if (cur >= 2) {
				int left = cur-1;
				while(true) {
					if(left == K) {
						System.out.println(d);
						return;
					} else if(left > K) {
						answer = Math.min(answer, d + left-K);
						break;
					} else { //left < K
						if(d < dist[left]) {
							dist[left] = d;
							q.add(left);
						}
						left <<= 1; //*2
					}
				}
			}
			int right = cur+1;
			while(true) {
				if(right == K) {
					System.out.println(d);
					return;
				} else if(right > K) {
					answer = Math.min(answer, d + right-K);
					break;
				} else { //left < K
					if(d < dist[right]) {
						dist[right] = d;
						q.add(right);
					}
					right <<= 1; //*2
				}
			}
		}
		System.out.println(answer);
	}
}