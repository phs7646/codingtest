package _0813;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/*
 * 메모리 : 32,732
 * 실행 시간 : 157
 * 
 * 바닥의 2부터 시작해서
 * 왼쪽이 있다면 쭉 가고 오른쪽이 있다면 쭉 간다음 위로 한칸씩 올라간다
 */
public class Solution_1210_Ladder1_박한성 {
	
	final static int N = 100;
	static int arr[][] = new int[N][N];
	
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		for(int t = 1;t <= 10;t++) {
			int T = Integer.parseInt(br.readLine().trim());
			//get input
			for(int i = 0;i < N-1;i++) {
				int j = 0;
				for(String s : br.readLine().trim().split(" ")) {
					arr[i][j++] = Integer.parseInt(s);
				}
			}
			
			
			int startx = 0;
			int j = 0;
			for(String s : br.readLine().trim().split(" ")) {
				arr[N-1][j] = Integer.parseInt(s);
				if(arr[N-1][j] == 2) {	
					startx = j;
				}
				j++;
			}
			int curx = startx;
			int cury = N-2;
			while(cury > 0) {
				if(curx > 0 && arr[cury][curx-1] == 1) {
					curx--;
					while(curx > 0 && arr[cury][curx-1] == 1) curx--;
				}else if(curx < N-1 && arr[cury][curx+1] == 1) {
					curx++;
					while(curx < N-1 && arr[cury][curx+1] == 1) curx++;
				}
				cury--;
			}
			sb.append('#').append(t).append(' ').append(curx).append('\n');
		}
		System.out.println(sb.toString());
	}
}
