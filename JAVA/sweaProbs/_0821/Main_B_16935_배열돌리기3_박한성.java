package _0821;

/**
 * 메모리 : 75492
 * 실행 시간 : 752
 * 시키는대로 구현
 */

import java.util.Scanner;

public class Main_B_16935_배열돌리기3_박한성 {

    static int N, M;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        M = scanner.nextInt();
        int R = scanner.nextInt();
        int[][] board = new int[N][M];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                board[i][j] = scanner.nextInt();
            }
        }

        for (int r = 0; r < R; r++) {
            int num = scanner.nextInt();
            switch (num) {
                case 1:
                    board = func1(board);
                    break;
                case 2:
                    board = func2(board);
                    break;
                case 3:
                    board = func3(board);
                    break;
                case 4:
                    board = func4(board);
                    break;
                case 5:
                    board = func5(board);
                    break;
                case 6:
                    board = func6(board);
                    break;
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }

        scanner.close();
    }

    static int[][] func1(int[][] v) {
        int[][] ret = new int[N][M];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                ret[i][j] = v[N - i - 1][j];
            }
        }
        return ret;
    }

    static int[][] func2(int[][] v) {
        int[][] ret = new int[N][M];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                ret[i][j] = v[i][M - 1 - j];
            }
        }
        return ret;
    }

    static int[][] func3(int[][] v) {
        int[][] ret = new int[M][N];
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                ret[i][j] = v[N - j - 1][i];
            }
        }
        int temp = N;
        N = M;
        M = temp;
        return ret;
    }

    static int[][] func4(int[][] v) {
        int[][] ret = new int[M][N];
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                ret[i][j] = v[j][M - 1 - i];
            }
        }
        int temp = N;
        N = M;
        M = temp;
        return ret;
    }

    static int[][] func5(int[][] v) {
        int[][] ret = new int[N][M];
        int hN = N / 2;
        int hM = M / 2;
        for (int i = 0; i < hN; i++) {
            for (int j = 0; j < hM; j++) {
                ret[i][j] = v[i + hN][j];
                ret[i][j + hM] = v[i][j];
                ret[i + hN][j] = v[i + hN][j + hM];
                ret[i + hN][j + hM] = v[i][j + hM];
            }
        }
        return ret;
    }

    static int[][] func6(int[][] v) {
        int[][] ret = new int[N][M];
        int hN = N / 2;
        int hM = M / 2;
        for (int i = 0; i < hN; i++) {
            for (int j = 0; j < hM; j++) {
                ret[i][j] = v[i][j + hM];
                ret[i][j + hM] = v[i + hN][j + hM];
                ret[i + hN][j] = v[i][j];
                ret[i + hN][j + hM] = v[i + hN][j];
            }
        }
        return ret;
    }
}
