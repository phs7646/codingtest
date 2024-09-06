package _0906;

/**
 * 메모리 : 21004
 * 실행 시간 : 113
 * treeSet에 만들 수 있는 모든 수 저장
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Iterator;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Solution_5658_보물상자비밀번호_박한성 {
	
	static int alphaToNum(char c) {
		if('0' <= c && c <= '9') return c-'0';
		else return 10+c-'A';
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine().trim());
		for(int t = 1;t <= T;t++) {
			StringTokenizer st = new StringTokenizer(br.readLine().trim());
			int N = Integer.parseInt(st.nextToken());
			int len = N>>2;
			int K = Integer.parseInt(st.nextToken());
			String s = br.readLine().trim();
			int arr[] = new int[N];
			for(int i = 0;i < N;i++) arr[i] = alphaToNum(s.charAt(i));
			Set<Integer> set = new TreeSet<>();
			
			
			for(int pad = 0;pad < len;pad++) {
				int index = pad;
				for(int l = 0;l < 4;l++) {
					//index부터 index+len-1까지로 수 만들어서 set에 넣기
					int cur = 0;
					for(int q = 0;q < len;q++) {
						cur = cur * 16 + arr[index%N];
						index++;
					}
					set.add(cur);
				}
			}
			int idx = 0;
			for(int n : set) {
				if(idx == set.size()-K) {
					sb.append('#').append(t).append(' ').append(n).append('\n');
					break;
				}
				idx++;
			}
			
		}
		System.out.print(sb);
	}

}
