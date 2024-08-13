package sweaProbs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;

public class m2383 {
	final static int bigINT = 2100000007;
	static int map[][] = new int[10][10];
	static int A[] = new int[10];
	static int B[] = new int[10];
	static int A_i,A_j,B_i,B_j;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine().trim());
		for(int t = 1;t <= T;t++) {
			
			//get Input
			int N = Integer.parseInt(br.readLine().trim());
			int num_exit = 0;
			for(int i = 0;i < N;i++) {
				int j = 0;
				for(String s : br.readLine().trim().split(" ")) {
					int cur = Integer.parseInt(s);
					if(cur > 1) {
						if(num_exit == 0) {
							A_i = i; A_j = j;
						} else {
							B_i = i; B_j = j;
						}
						num_exit++;
					}
					map[i][j++] = cur;
					
				}
			}
			
			//pre-process
			int num_human = 0;
			for(int i = 0;i < N;i++) {
				for(int j = 0;j < N;j++) {
					if(map[i][j] == 1) {
						A[num_human] = Math.abs(i-A_i) + Math.abs(j-A_j) + 1;
						B[num_human] = Math.abs(i-B_i) + Math.abs(j-B_j) + 1;
						num_human++;
					}
				}
			}
			int delayA = map[A_i][A_j];
			int delayB = map[B_i][B_j];
			
			//logic
			int answer = bigINT;
			int max_bit = 1 << num_human;
			for(int bit = 0;bit < max_bit;bit++) {
				//test bit
				PriorityQueue<Integer> waitqA = new PriorityQueue<>();
				PriorityQueue<Integer> waitqB = new PriorityQueue<>();
				for(int i = 0;i < num_human;i++) {
					if((bit & (1<<i)) != 0) {
						waitqA.add(A[i]);
					} else waitqB.add(B[i]);
				}
				int timeA = needTime(delayA,waitqA);
				int timeB = needTime(delayB,waitqB);
				int cur_time = Math.max(timeA,timeB);
				answer = Math.min(answer, cur_time);
			}
			
			//output
			sb.append('#').append(t).append(' ').append(answer).append('\n');
		}
		System.out.println(sb.toString());
	}
	static int needTime(int delay, PriorityQueue<Integer> waitQ) {
		//delay를 가진 출구가 waitQ를 모두 처리하기 위해 걸리는 시간
		Queue<Integer> q = new LinkedList<>(); //현재 계단에 올라가있는 사람들의 탈출시간
		int time = 0;
		while(!waitQ.isEmpty() || !q.isEmpty()) {
			
			//time sleep : 다음 이벤트는 waitQ.front 혹은 q.front에서 일어남
			time = bigINT;
			if(q.size() == 3) time = q.peek();
			else {
				if(!q.isEmpty()) time = Math.min(time, q.peek());
				if(!waitQ.isEmpty()) time = Math.min(time, waitQ.peek());
			}
			
			//q에 탈출시간이 지난 사람들을 unload한다
			while(!q.isEmpty()) {
				if(q.peek() <= time) q.poll();
				else break;
			}
			//waitq에 있는사람을 넣을 수 있다면 넣는다.
			while(q.size() < 3 && !waitQ.isEmpty()) {
				if(waitQ.peek() <= time) {
					waitQ.poll();
					q.add(time + delay);
				} else break;
			}
			
		}
		return time;
	}
}
