package _0816;

/**
 * 메모리 : 20548
 * 실행 시간 : 300
 * 맨처음 P 문자열의 갯수를 카운팅하고
 * 이후 부터는 맨 앞 문자를 뺴고 맨 뒷문자를 더해가면서 순회
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main_B_12891_DNA비밀전호_박한성 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine().trim());
		int S = Integer.parseInt(st.nextToken());
		int P = Integer.parseInt(st.nextToken());
		String str = br.readLine().trim();
		int needcount[] = new int[4];
		st = new StringTokenizer(br.readLine().trim());
		for(int i = 0;i < 4;i++) {
			needcount[i] = Integer.parseInt(st.nextToken());
		}
		int curcount[] = new int[4];
		for(int i = 0;i < P;i++) {
			if(str.charAt(i) == 'A') curcount[0]++;
			else if(str.charAt(i) == 'C') curcount[1]++;
			else if(str.charAt(i) == 'G') curcount[2]++;
			else curcount[3]++;
		}
		
		int answer = 0;
		
		for(int head = 0;head <= S-P;head++) {
			
			//check if count
			boolean flag = true;
			for(int i = 0;i < 4;i++) {
				if(curcount[i] < needcount[i]) {
					flag = false;
					break;
				}
			}
			if(flag) answer++;
			
			//progress
			if(head < S-P) {
				int tail = head+P;
				char c1 = str.charAt(head);
				char c2 = str.charAt(tail);
				
				if(c1 == 'A') curcount[0]--;
				else if(c1 == 'C') curcount[1]--;
				else if(c1 == 'G') curcount[2]--;
				else curcount[3]--;
				
				if(c2 == 'A') curcount[0]++;
				else if(c2 == 'C') curcount[1]++;
				else if(c2 == 'G') curcount[2]++;
				else curcount[3]++;
			}
			
			
		}
		System.out.println(answer);
	}
}
