package _0813;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.StringTokenizer;


/*
 * 메모리 : 20884
 * 실행 시간 : 1284
 * 
 * 1. input을 내림차순 정렬한다 (규영이가 카드를 내는 순서가 바뀌어도 경우의 수는 같음)
 * 2. dfs로 각 순서에 낼 카드를 결정하고 점수를 계산한다 (가능한 큰 수 부터 낸다)
 * 3. dfs 중간에 가지거나 잃은 점수가 HALF를 넘어가면 즉시 끝난다 이때 남은카드수!만큼 센다.
 */

public class Solution_6808_규영이와인영이의카드게임_박한성2 {
	final static int N = 18;
	final static int hN = N>>1;
	final static int FACTS[] = {1,1,2,6,24,120,720,5040,40320,362880};
	final static int HALF = 171>>1; //sum(1..18)/2
	static boolean visited[];
	static List<Integer> A;
	static int answer = 0;
	static int gain = 0;
	static int losed = 0;
	static void dfs(int pos) {
		if(pos == hN) {
			if(gain > losed) answer++;
			return;
		}
		if(gain > HALF) {
			answer += FACTS[9-pos];
			return;
		} else if(losed > HALF) {
			return;
		}
		
		//pos에서 뭘낼지 정하자
		for(int i = 18;i >= 1;i--) {
			if(visited[i]) continue;
			visited[i] = true;
			int score = A.get(pos) + i;
			if(A.get(pos) < i) {
				gain += score;
				dfs(pos+1);
				gain -= score;
			} else {
				losed += score;
				dfs(pos+1);
				losed -= score;
			}
			visited[i] = false;
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine().trim());
		for(int t = 1;t <= T;t++) {
			//initialize
			visited = new boolean[N+1];
			A = new ArrayList<>(hN);
			answer = 0;
			//get input
			StringTokenizer st = new StringTokenizer(br.readLine().trim());
			for(int i = 0;i < hN;i++) {
				int k = Integer.parseInt(st.nextToken());
				A.add(k);
				visited[k] = true;
			}
			A.sort(Comparator.reverseOrder());
			
			dfs(0);
			
			sb.append('#').append(t).append(' ').append(FACTS[9]-answer).append(' ').append(answer).append('\n');
		}
		System.out.println(sb.toString());
	}
}
