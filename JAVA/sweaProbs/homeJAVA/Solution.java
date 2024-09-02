import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	static int D,W,K;
	static int answer;
	static int map[];
	static boolean isOK() {
		//map이 합격기준 K를 통과하는지?
		for(int j = 0;j < W;j++) {
			//j열을 bit로 바꾸기!
			int bit = 0;
			
			for(int i = 0;i < D;i++) {
				//i,j
				if((map[i] & (1<<j)) > 0) {
					//map[i][j] 가 1이구나
					bit |= (1<<i);
				}
			}
			
			int bit2 = ~bit;
			
			boolean flag = false;
			int answerBit = (1<<K)-1;
			
			for(int shift = 0;shift <= D-K;shift++) {
				int check = answerBit << shift;
				if((bit & check) == check) {
					//얘 검사 통과!!
					flag = true;
					break;
				}
				if((bit2 & check) == check) {
					flag = true;
					break;
				}
			}
			if(!flag) return false;
		}
		return true;
	}
	
	static void dfs(int pos,int cnt) {
		
		if(cnt >= answer) return; //가지치기
		
		//탈출
		if(pos == D) {
			if(isOK()) {
				answer = Math.min(cnt, answer);
			}
			return;
		}
		
		//로직
		int tmp = map[pos];
		
		//안칠하기
		
		dfs(pos+1,cnt);
		
		//A칠하기
		map[pos] = 0;
		dfs(pos+1,cnt+1);
		map[pos] = tmp;
		
		//B칠하기
		map[pos] = (1<<W)-1;
		dfs(pos+1,cnt+1);
		map[pos] = tmp;
	}
	
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int T = Integer.parseInt(br.readLine());
		for(int t = 1;t <= T;t++) {
			//input
			StringTokenizer st = new StringTokenizer(br.readLine());
			D = Integer.parseInt(st.nextToken());
			W = Integer.parseInt(st.nextToken());
			K = Integer.parseInt(st.nextToken());
			answer = K;
			map = new int[D];
			//input
			for(int i = 0;i < D;i++) {
				st = new StringTokenizer(br.readLine());
				for(int j = 0;j < W;j++) {
					int c = Integer.parseInt(st.nextToken());
					if(c == 1)
						map[i] |= (1<<j);
				}
			} //input end
			
			
			//logic
			dfs(0,0);
			
			//output
			sb.append('#').append(t).append(' ').append(answer).append('\n');
		}
		System.out.print(sb);
	}
}
