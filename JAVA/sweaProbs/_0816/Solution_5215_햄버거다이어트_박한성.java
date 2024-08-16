package _0816;

/**
 * 메모리 : 27496
 * 실행 시간 : 332
 * dfs로 각 재료를 고르거나 고르지 않거나
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Solution_5215_햄버거다이어트_박한성 {
	static class ing {
		int score;
		int calorie;
		ing(int s,int c) {score = s; calorie = c;}
		@Override
		public String toString() {
			return "ing [score=" + score + ", calorie=" + calorie + "]";
		}
	}
	
	static int N,L;
	static int answer;
	static int cur_cos;
	static int cur_cal;
	static List<ing> list;
	static void dfs(int pos) {
		if(pos >= N ) {
			answer = Math.max(answer, cur_cos);
			return;
		}
		//pos를 고르거나 고르지 않거나
		//그냥
		dfs(pos+1);
		//고르기
		if(cur_cal + list.get(pos).calorie <= L) {
			cur_cos += list.get(pos).score;
			cur_cal += list.get(pos).calorie;
			dfs(pos+1);
			cur_cos -= list.get(pos).score;
			cur_cal -= list.get(pos).calorie;
		}
	}
	static StringBuilder sb;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		sb = new StringBuilder();
		
		int T = Integer.parseInt(br.readLine().trim());
		for(int t = 1;t <= T;t++) {
			StringTokenizer st = new StringTokenizer(br.readLine().trim());
			N = Integer.parseInt(st.nextToken());
			L = Integer.parseInt(st.nextToken());
			list = new ArrayList<>(N);
			for(int i = 0;i < N;i++) {
				st = new StringTokenizer(br.readLine().trim());
				list.add(new ing(Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken())));
			}
			list.sort((i1,i2)->i1.calorie-i2.calorie);
			//for(ing i : list) System.out.println(i);
			answer = 0;
			cur_cos = 0;
			cur_cal = 0;
			dfs(0);
			
			sb.append('#').append(t).append(' ').append(answer).append('\n');
		}
		System.out.println(sb);
	}

}
