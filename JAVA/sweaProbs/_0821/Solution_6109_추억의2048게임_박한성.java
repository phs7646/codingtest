package _0821;

/**
 * 메모리 : 30780
 * 실행 시간 : 162
 * 시키는대로 구현
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution_6109_추억의2048게임_박한성 {
	
	static void logic(int[] input) {
		//push left
		int count = 0; //insert index
		for(int index = 0;index < input.length;index++) {
			if(input[index] == 0) continue;
			input[count++] = input[index];
		}
		for(;count < input.length;count++) {
			input[count] = 0;
		}
		
		//merge
		int index = 0;
		count = 0;
		while(index + 1 < input.length) {
			//index와 index+1이 같으면 합쳐서 저장, 아니면 왼쪽만 저장
			if(input[index] == input[index+1]) {
				input[count++] = 2*input[index];
				index += 2;
			} else {
				input[count++] = input[index];
				index += 1;
			}
		}
		if(index < input.length) {
			input[count++] = input[index];
		}
		for(;count < input.length;count++) input[count] = 0;
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine().trim());
		for(int t = 1;t <= T;t++) {
			StringTokenizer st = new StringTokenizer(br.readLine().trim());
			int N = Integer.parseInt(st.nextToken());
			String dir = st.nextToken();
			int map[][] = new int[N][N];
			for(int i = 0;i < N;i++) {
				st = new StringTokenizer(br.readLine().trim());
				for(int j = 0;j < N;j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			if(dir.charAt(0) == 'u') {
				for(int j = 0;j < N;j++) {
					int tmp[] = new int[N];
					for(int i = 0;i < N;i++) tmp[i] = map[i][j];
					logic(tmp);
					for(int i = 0;i < N;i++) map[i][j] = tmp[i];
				}
			} else if(dir.charAt(0) == 'd') {
				for(int j = 0;j < N;j++) {
					int tmp[] = new int[N];
					for(int i = 0;i < N;i++) tmp[i] = map[N-i-1][j];
					logic(tmp);
					for(int i = 0;i < N;i++) map[N-i-1][j] = tmp[i];
				}
			} else if(dir.charAt(0) == 'l') {
				for(int i = 0;i < N;i++) {
					int tmp[] = new int[N];
					for(int j = 0;j < N;j++) tmp[j] = map[i][j];
					logic(tmp);
					for(int j = 0;j < N;j++) map[i][j] = tmp[j];
				}
			} else {
				for(int i = 0;i < N;i++) {
					int tmp[] = new int[N];
					for(int j = 0;j < N;j++) tmp[j] = map[i][N-j-1];
					logic(tmp);
					for(int j = 0;j < N;j++) map[i][N-j-1] = tmp[j];
				}
			}
			
			
			//output
			sb.append('#').append(t).append('\n');
			for(int i = 0;i < N;i++) {
				for(int j = 0;j < N;j++) sb.append(map[i][j]).append(' ');
				sb.append('\n');
			}
		}
		System.out.println(sb);
	}

}
