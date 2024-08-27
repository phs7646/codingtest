package _0827;

/**
 * 메모리 : 19668
 * 실행 시간 : 228
 * BFS 두번
 */

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Main_B_10026_적록색약_박한성 {
    static class Pair {
        int first, second;
        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    static String[] map = new String[100];
    static boolean[][] visited1 = new boolean[100][100];
    static boolean[][] visited2 = new boolean[100][100];
    static Pair[] moves = {new Pair(0, 1), new Pair(1, 0), new Pair(-1, 0), new Pair(0, -1)};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        sc.nextLine();  // 개행 문자 제거
        for (int i = 0; i < N; i++) {
            map[i] = sc.nextLine();
        }

        // normal
        int ans1 = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (visited1[i][j]) continue;
                ans1++;
                char c = map[i].charAt(j);
                Queue<Pair> q = new LinkedList<>();
                visited1[i][j] = true;
                q.add(new Pair(i, j));
                while (!q.isEmpty()) {
                    Pair cur = q.poll();
                    for (int d = 0; d < 4; d++) {
                        int ny = cur.first + moves[d].first;
                        int nx = cur.second + moves[d].second;
                        if (0 <= nx && nx < N && 0 <= ny && ny < N && map[ny].charAt(nx) == c && !visited1[ny][nx]) {
                            visited1[ny][nx] = true;
                            q.add(new Pair(ny, nx));
                        }
                    }
                }
            }
        }

        // other
        int ans2 = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (visited2[i][j]) continue;
                ans2++;
                char c = map[i].charAt(j);
                Queue<Pair> q = new LinkedList<>();
                visited2[i][j] = true;
                q.add(new Pair(i, j));
                while (!q.isEmpty()) {
                    Pair cur = q.poll();
                    for (int d = 0; d < 4; d++) {
                        int ny = cur.first + moves[d].first;
                        int nx = cur.second + moves[d].second;
                        if (0 <= nx && nx < N && 0 <= ny && ny < N && !visited2[ny][nx]) {
                            if (c == map[ny].charAt(nx) || 
                                (c == 'R' && map[ny].charAt(nx) == 'G') || 
                                (c == 'G' && map[ny].charAt(nx) == 'R')) {
                                visited2[ny][nx] = true;
                                q.add(new Pair(ny, nx));
                            }
                        }
                    }
                }
            }
        }

        System.out.println(ans1 + " " + ans2);
        sc.close();
    }
}
