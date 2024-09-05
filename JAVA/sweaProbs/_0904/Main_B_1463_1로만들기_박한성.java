package _0904;

/**
 * 메모리 : 18648
 * 실행 시간 : 176
 * bfs
 */

import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;
import java.util.Scanner;

public class Main_B_1463_1로만들기_박한성 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		if(N==1) {
			System.out.println(0);
			return;
		} else if(N==2 || N==3) {
			System.out.println(1);
			return;
		}
		boolean visited[] = new boolean[N];
		Queue<Integer> q = new ArrayDeque<>();
		q.add(N);
		int answer = 1;
		while(!q.isEmpty()) {
			int qSize = q.size();
			for(int qs = 0;qs < qSize;qs++) {
				int cur = q.poll();
				if(cur == 1) {
					System.out.println(answer-1);
					return;
				}
				if(cur == 2 || cur == 3) {
					System.out.println(answer);
					return;
				}
				if(cur%2==0 && !visited[cur/2]) {
					visited[cur/2] = true;
					q.add(cur/2);
				}
				if(cur%3==0 && !visited[cur/3]) {
					visited[cur/3] = true;
					q.add(cur/3);
				}
				if(!visited[cur-1]) {
					visited[cur-1]=true;
					q.add(cur-1);
				}
			}
			answer++;
		}
		
	}

}
