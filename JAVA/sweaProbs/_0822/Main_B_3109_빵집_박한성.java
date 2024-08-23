package _0822;

/**
 * 메모리 : 29644
 * 실행 시간 : 364
 * 매 선택마다 가능한 위쪽에 있는 파이프를 선택하고,
 * 다음 파이스 생성시 이전 파이프 위치부터 시작한다.
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_B_3109_빵집_박한성 {

	static int R, C;
	static int ans = 0;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine().trim());
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());

		boolean[][] map = new boolean[R][C];

		for (int i = 0; i < R; i++) {
			String line = br.readLine().trim();
			for (int j = 0; j < C; j++) {
				if (line.charAt(j) == 'x') {
					map[i][j] = true;
				}
			}
		}

		int[] current = new int[C];

		while (true) {
			for (int c = 0; c < C; c++) {
				//if invalid, then find next
				if (map[current[c]][c] || (c - 1 >= 0 && current[c - 1] - 1 > current[c])
						|| (c + 1 < C && current[c + 1] - 1 > current[c])) {
					current[c] = findNext(current[c], c, map);
					if (current[c] >= R) {
						System.out.println(ans);
						return;
					}
					c = Math.max(c-2, -1);
				}
			}
			ans++;

			for (int c = 0; c < C; c++) {
				current[c] = findNext(current[c], c, map);
				if (current[c] == R) {
					System.out.println(ans);
					return;
				}
			}
		}
	}

	public static int findNext(int r, int c, boolean[][] map) {
		int current = r + 1;
		while (current < R && map[current][c])
			current++;
		return current;
	}
}
