package _0827;

/**
 * 메모리 : 14768
 * 실행 시간 : 132
 * dfs로 사전순으로 순회하며 조건을 만족할 때마다 출력
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main_B_1759_암호만들기_박한성 {
	
	static int L,C;
	static List<Character> alphas;
	static char ret[];
	static boolean isMOEM[];
	static int cur_count;
	static void dfs(int pos,int cnt) {
		if(cnt == L) {
			if(cur_count >= 1 && cur_count <= L-2) {
				for(int i = 0;i < L;i++) System.out.print(ret[i]);
				System.out.println();
			}
			return;
		}
		if(C - pos + cnt < L) return;
		
		//고르기
		ret[cnt] = alphas.get(pos);
		if(isMOEM[ret[cnt]-'a']) cur_count++;
		dfs(pos+1,cnt+1);
		if(isMOEM[ret[cnt]-'a']) cur_count--;
		//안고르기
		dfs(pos+1,cnt);
		
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine().trim());
		L = Integer.parseInt(st.nextToken()); //모음의 갯수는 1개 이상 L-2개 이하
		C = Integer.parseInt(st.nextToken());
		
		alphas = new ArrayList<>(); 
		String line = br.readLine().trim();
		for(int i = 0;i < C;i++) {
			alphas.add(line.charAt(2*i));
		}
		alphas.sort(null);
		
		
		isMOEM = new boolean[26];
		isMOEM['a'-'a'] = true;
		isMOEM['e'-'a'] = true;
		isMOEM['i'-'a'] = true;
		isMOEM['o'-'a'] = true;
		isMOEM['u'-'a'] = true;
		
		cur_count = 0;
		ret = new char[L];
		dfs(0,0);
	}

}
