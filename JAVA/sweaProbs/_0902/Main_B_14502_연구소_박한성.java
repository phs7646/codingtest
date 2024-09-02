package _0902;

/**
 * 메모리 : 139156
 * 실행 시간 : 484
 * 구현
 */

import java.util.*;

public class Main_B_14502_연구소_박한성 {
    static int[][] MAP = new int[8][8];
    static int N, M;
    static List<int[]> virus = new ArrayList<>();
    static List<int[]> zero = new ArrayList<>();
    static int ans;

    public static void BFS() {
        int[][] m = new int[N][M];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                m[i][j] = MAP[i][j];

        Queue<int[]> q = new LinkedList<>();
        for (int[] p : virus) {
            q.add(p);
        }

        while (!q.isEmpty()) {
            int[] p = q.poll();
            int y = p[0];
            int x = p[1];
            
            if (y + 1 < N && m[y + 1][x] == 0) {
                m[y + 1][x] = 2;
                q.add(new int[] { y + 1, x });
            }
            if (y - 1 >= 0 && m[y - 1][x] == 0) {
                m[y - 1][x] = 2;
                q.add(new int[] { y - 1, x });
            }
            if (x + 1 < M && m[y][x + 1] == 0) {
                m[y][x + 1] = 2;
                q.add(new int[] { y, x + 1 });
            }
            if (x - 1 >= 0 && m[y][x - 1] == 0) {
                m[y][x - 1] = 2;
                q.add(new int[] { y, x - 1 });
            }
        }

        int count = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (m[i][j] == 0) count++;
            }
        }

        if (ans < count) {
            ans = count;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                MAP[i][j] = sc.nextInt();
                if (MAP[i][j] == 0) zero.add(new int[] { i, j });
                else if (MAP[i][j] == 2) virus.add(new int[] { i, j });
            }
        }

        int num_zero = zero.size();
        ans = 0;

        for (int i = 0; i < num_zero - 2; i++) {
            int[] first = zero.get(i);
            MAP[first[0]][first[1]] = 1;
            for (int j = i + 1; j < num_zero - 1; j++) {
                int[] second = zero.get(j);
                MAP[second[0]][second[1]] = 1;
                for (int k = j + 1; k < num_zero; k++) {
                    int[] third = zero.get(k);
                    MAP[third[0]][third[1]] = 1;
                    BFS();
                    MAP[third[0]][third[1]] = 0;
                }
                MAP[second[0]][second[1]] = 0;
            }
            MAP[first[0]][first[1]] = 0;
        }

        System.out.println(ans);
        sc.close();
    }
}
