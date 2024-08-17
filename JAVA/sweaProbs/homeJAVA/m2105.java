import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class m2105 {
	
	static int[][] map;
	static int[] dy = {-1,1,1,-1};
	static int[] dx = {1,1,-1,-1};
	static int answer = 0;
	static int cur = 0;
	static boolean visited[][];
	static boolean ate[];
	static int starti;
	static int startj;
	static int N;
	
	static boolean isValid(int i,int j) {
		return (0 <= i && i < N && 0 <= j && j < N);
	}
	
	static void dfs(int i,int j,int dir) {
		//탈출
		if(dir == 3 && i == starti && j == startj) {
			answer = Math.max(answer,cur);
			return;
		}
		//로직 : 그냥 한칸 간다. 혹은 방향전화해서 한칸간다.
		
		//가지치기 : dir이 2인데 이미 starti 와 startj를 넘어버렸다면 즉시 리턴
		if(dir == 2) {
			if(starti+startj >= i+j) return;
		}
		
		//그냥가기
		int nexti = i + dy[dir];
		int nextj = j + dx[dir];
		if(isValid(nexti,nextj) && !visited[nexti][nextj] && !ate[map[nexti][nextj]]) {
			visited[nexti][nextj] = true;
			cur++;
			ate[map[nexti][nextj]] = true;
			dfs(nexti,nextj,dir);
			ate[map[nexti][nextj]] = false;
			cur--;
			visited[nexti][nextj] = false;
		}
		//방향 전환하기
		if(dir < 3) {
			dir++;
			nexti = i + dy[dir];
			nextj = j + dx[dir];
			if(isValid(nexti,nextj) && !visited[nexti][nextj] && !ate[map[nexti][nextj]]) {
				visited[nexti][nextj] = true;
				ate[map[nexti][nextj]]  =true;
				cur++;
				dfs(nexti,nextj,dir);
				cur--;
				ate[map[nexti][nextj]] = false;
				visited[nexti][nextj] = false;
			}
		}
	}
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int T = Integer.parseInt(br.readLine().trim());
		for(int t = 1;t <= T;t++) {
			N = Integer.parseInt(br.readLine().trim());
			map = new int[N][N];
			for(int i = 0;i < N;i++) {
				int j = 0;
				for(String s : br.readLine().split(" ")) {
					map[i][j++] = Integer.parseInt(s);
				}
			}
			visited = new boolean[N][N];
			ate = new boolean[101];
			answer = -1;
			for(int i = 1;i < N;i++) {
				for(int j = 0;j < N-1;j++) {
					cur = 1;
					visited[i-1][j+1] = true;
					ate[map[i-1][j+1]] = true;
					starti = i;
					startj = j;
					dfs(i-1,j+1,0);
					ate[map[i-1][j+1]] = false;
					visited[i-1][j+1] = false;
				}
			}
			sb.append('#').append(t).append(' ').append(answer).append('\n');
		}
		System.out.println(sb.toString());
	}

}
