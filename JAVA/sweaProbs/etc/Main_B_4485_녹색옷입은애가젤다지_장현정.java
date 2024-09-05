package etc;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;
import java.util.StringTokenizer;
/*
 * bfs ? dfs ?
 * 이동해가면서 더한 루피 더했을 때 최소값 구하기
 * bfs map 하나 더 생성해서 최소값 정해주기
 * 
 */
public class Main_B_4485_녹색옷입은애가젤다지_장현정 {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int t = 1;
        while (true) {
            int N = Integer.parseInt(br.readLine().trim());
            if (N == 0)
                break;
            int arr[][] = new int[N][N];
            for (int i = 0; i < N; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine().trim());
                for (int j = 0; j < N; j++) {
                    arr[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            // input end
            int map[][] = new int[N][N]; // 각 최솟값 넣을 거
            for (int i = 0; i < N; i++)
                Arrays.fill(map[i], Integer.MAX_VALUE);
            int dy[] = { -1, 0, 1, 0 };
            int dx[] = { 0, 1, 0, -1 };
            // bfs 시작
            Queue<int[]> q = new ArrayDeque<>();
            q.add(new int[] { 0, 0 });
            map[0][0] = arr[0][0];
            while (!q.isEmpty()) {
                int index[] = q.poll();
                int y = index[0];
                int x = index[1];
                for (int d = 0; d < 4; d++) {
                    int ny = y + dy[d];
                    int nx = x + dx[d];
                    if (ny < 0 || ny >= N || nx < 0 || nx >= N)
                        continue;
                    int newCost = map[y][x] + arr[ny][nx];
                    if(map[ny][nx] > newCost) {
                    	map[ny][nx] = newCost;
                    	q.add(new int[] {ny,nx});
                    }
                }
            }
            sb.append("Problem ").append(t).append(": ").append(map[N - 1][N - 1]).append('\n');
        } // while end
        System.out.println(sb);
    }
}