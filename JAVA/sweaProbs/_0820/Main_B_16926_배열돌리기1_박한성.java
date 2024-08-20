package _0820;

/**
 * 메모리 : 114532
 * 실행 시간: 1504
 * 구현
 */

import java.util.Scanner;

public class Main_B_16926_배열돌리기1_박한성 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int M = sc.nextInt();
        int R = sc.nextInt();

        int[][] arr = new int[N][M];
        int[][] arr2 = new int[N][M];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                arr[i][j] = sc.nextInt();
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int padding = Math.min(Math.min(i, N - i - 1), Math.min(j, M - j - 1));
                int num = R % (2 * (N - 2 * padding - 1) + 2 * (M - 2 * padding - 1));
                int[] newPos = newpos(i, j, num, padding, N, M);
                int y = newPos[0];
                int x = newPos[1];
                arr2[y][x] = arr[i][j];
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                System.out.print(arr2[i][j] + " ");
            }
            System.out.println();
        }

        sc.close();
    }

    public static int[] newpos(int i, int j, int num, int padding, int N, int M) {
        if (num == 0) {
            return new int[]{i, j};
        }
        if (i == padding && j > padding) {
            int dist = Math.min(num, j - padding);
            num -= dist;
            j -= dist;
        }
        if (num == 0) {
            return new int[]{i, j};
        }
        if (j == padding && i < N - padding - 1) {
            int dist = Math.min(num, N - padding - i - 1);
            num -= dist;
            i += dist;
        }
        if (num == 0) {
            return new int[]{i, j};
        }
        if (i == N - padding - 1 && j < M - padding - 1) {
            int dist = Math.min(num, M - padding - j - 1);
            num -= dist;
            j += dist;
        }
        if (num == 0) {
            return new int[]{i, j};
        }
        if (j == M - padding - 1 && i > padding) {
            int dist = Math.min(num, i - padding);
            num -= dist;
            i -= dist;
        }
        return newpos(i, j, num, padding, N, M);
    }
}
