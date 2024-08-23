package _823;

/**
 * 메모리 : 21444
 * 실행 시간 : 123
 * 시뮬레이션
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_1873_상호의배틀필드_박한성 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine().trim());
		int dy[] = {-1,1,0,0}; //UDLR
		int dx[] = {0,0,-1,1};
		for(int t = 1;t <= T;t++) {
			StringTokenizer st = new StringTokenizer(br.readLine().trim());
			int H = Integer.parseInt(st.nextToken());
			int W = Integer.parseInt(st.nextToken());
			String[] map = new String[H];
			int y=0,x=0;
			int dir=0;
			for(int i = 0;i < H;i++) {
				map[i] = br.readLine().trim();
				for(int j = 0;j < W;j++) {
					char c = map[i].charAt(j);
					if(c == '<') {
						y = i; x = j; dir = 2;
						map[i] = map[i].replace('<', '.');
					} else if(c == '>') {
						y = i; x = j; dir = 3;
						map[i] = map[i].replace('>', '.');
					} else if(c == 'v') {
						y = i; x = j; dir = 1;
						map[i] = map[i].replace('v', '.');
					} else if(c == '^') {
						y = i; x = j; dir = 0;
						map[i] = map[i].replace('^', '.');
					} 
				}
			}
			
			int N = Integer.parseInt(br.readLine().trim());
			String command = br.readLine().trim();
			for(int n = 0;n < N;n++) {
				
				char c = command.charAt(n);
				//shoot
				if(c=='S') {
					int i = y,j=x;
					while(true) {
						i += dy[dir];
						j += dx[dir];
						if(0 > i || i >= H || 0 > j || j >= W) break;
						if(map[i].charAt(j) == '#') break;
						if(map[i].charAt(j) == '*') {
							map[i] = map[i].substring(0, j) + "." + map[i].substring(j+1);
							break;
						}
					}
					continue;
				}
				//move
				else if(c=='U') {
					dir = 0;
				} else if(c=='D') {
					dir = 1;
				} else if(c =='L') {
					dir = 2;
				} else if(c == 'R') {
					dir = 3;
				}
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				if(0 <= ny && ny < H && 0 <= nx && nx < W && map[ny].charAt(nx) == '.') {
					y = ny;
					x = nx;
				}
			}
			char last = '^';
			if(dir == 1) last = 'v';
			else if(dir == 2) last = '<';
			else if(dir == 3) last = '>';
			map[y] = map[y].substring(0,x) + last + map[y].substring(x+1);
			sb.append('#').append(t).append(' ');
			for(int i = 0;i < H;i++) sb.append(map[i]).append('\n');
		}
		System.out.print(sb);
	}

}
