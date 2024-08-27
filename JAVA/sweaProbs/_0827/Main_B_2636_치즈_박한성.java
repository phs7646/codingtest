package _0827;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

/**
 * 메모리 : 25396
 * 실행 시간 : 268
 * BFS
 *
 */

public class Main_B_2636_치즈_박한성 {
    static int[][] board = new int[100][100]; // 0 빈땅, 1 치즈, n : n-1시간째에 녹아없어진 치즈
    static int N, M;
    static int[][] moves = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        int num_left = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                board[i][j] = sc.nextInt();
                if (board[i][j] == 1) num_left++;
            }
        }

        int day = 0;

        while (num_left > 0) {
            // day인 날 진행
            // 1을 만나면 day+2로 마크하고 멈추고,
            // day+2를 만나면 멈춤
            Queue<int[]> q = new LinkedList<>();
            boolean[][] visited = new boolean[N][M];
            q.add(new int[]{0, 0});
            visited[0][0] = true;

            while (!q.isEmpty()) {
                int[] p = q.poll();
                for (int d = 0; d < 4; d++) {
                    int i = p[0] + moves[d][0];
                    int j = p[1] + moves[d][1];
                    if (i < 0 || i >= N || j < 0 || j >= M) continue;
                    if (visited[i][j]) continue;
                    visited[i][j] = true;
                    if (board[i][j] == 1) {
                        board[i][j] = day + 2;
                        num_left--;
                    } else if (board[i][j] != day + 2) {
                        q.add(new int[]{i, j});
                    }
                }
            }
            day++;
        }

        // 치즈가 마지막으로 남아있던 시간 계산
        int num = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] == day + 1) num++;
            }
        }

        System.out.println(day);
        System.out.println(num);
        sc.close();
    }
}
