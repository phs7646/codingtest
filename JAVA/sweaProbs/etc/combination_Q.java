package etc;
import java.util.Scanner;
/**
 * 
N개의 요소 중 R개의 뽑는 모든 경우의 수를 출력하기
출력 시, StringBuilder를 사용하자.


입력 예시
N R
배열 요소
====
4 2
7 8 9 10

====
출력 예시
====
7 8
7 9
7 10
8 9
8 10
9 10
====
 */
public class combination_Q {
	static int N;	//arr의 크기(요소의 개수
	static int R;	//뽑을 개수
	
	static int[] arr;
	static StringBuilder sb;
	static int[] cur;
	static void dfs(int pos,int count) {
		if(count == R) {
			for(int i = 0;i < R;i++) sb.append(cur[i]).append(' ');
			sb.append('\n');
			return;
		}
		for(int i = pos+1; i <= N - (R-count);i++) {
			cur[count] = arr[i];
			dfs(i,count+1);
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		N = sc.nextInt();
		R = sc.nextInt();
		
		cur = new int[R];
		arr = new int[N];
		
		for(int i=0; i<N; i++) arr[i] = sc.nextInt();
		
		
		sb = new StringBuilder();
		dfs(-1,0);
		System.out.print(sb.toString());
		
		
	}


	
}