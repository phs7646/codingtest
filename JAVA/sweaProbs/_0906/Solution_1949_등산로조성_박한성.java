package _0906;

/**
 * 메모리 : 27412
 * 실행 시간 : 178
 * dfs
 */

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Solution_1949_등산로조성_박한성 {
    static int[][] board = new int[8][8];
    static int N, K;
    static int answer = 0;
    static int cur = 0;
    static boolean[][] visited = new boolean[8][8];
    static int[][] moves = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    static boolean constructed;

    public static void dfs(int i, int j) {
        // 지금 cur_val 부터 전부 고르면 constructed 인 경우 cur_val-1 ~ 1 까지 골라짐
        // !constructed인 경우 curval-1 ~ 0까지 골라짐
        int max_count = constructed ? board[i][j] - 1 : board[i][j];
        if (max_count + cur < answer) return; // 전부 다 골라도 max보다 적음
        answer = Math.max(answer, cur);
        for (int d = 0; d < 4; d++) {
            int _i = i + moves[d][0];
            int _j = j + moves[d][1];
            if (_i < 0 || _i >= N || _j < 0 || _j >= N) continue;
            if (visited[_i][_j]) continue;
            if (board[i][j] > board[_i][_j]) {
                // 방문할 수 있음
                cur++;
                visited[_i][_j] = true;
                dfs(_i, _j);
                visited[_i][_j] = false;
                cur--;
            } else if (!constructed && board[_i][_j] - K < board[i][j]) {
                // construct하고 진행
                constructed = true;
                int tmp = board[_i][_j];
                board[_i][_j] = board[i][j] - 1;
                visited[_i][_j] = true;
                cur++;
                dfs(_i, _j);
                cur--;
                visited[_i][_j] = false;
                board[_i][_j] = tmp; // 복원
                constructed = false;
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int t = 1; t <= T; t++) {
            // 초기화
            answer = 0;
            cur = 0;
            N = sc.nextInt();
            K = sc.nextInt();
            int max_val = 0;
            List<int[]> v = new ArrayList<>();
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    board[i][j] = sc.nextInt();
                    if (board[i][j] > max_val) {
                        max_val = board[i][j];
                        v.clear();
                        v.add(new int[]{i, j});
                    } else if (board[i][j] == max_val) {
                        v.add(new int[]{i, j});
                    }
                }
            }

            for (int[] p : v) {
                cur = 1;
                visited[p[0]][p[1]] = true;
                dfs(p[0], p[1]);
                visited[p[0]][p[1]] = false;
            }

            System.out.println("#" + t + " " + answer);
        }
        sc.close();
    }
}
