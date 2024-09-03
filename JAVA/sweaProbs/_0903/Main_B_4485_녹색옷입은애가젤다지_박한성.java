package _0903;

/**
 * 메모리 : 55896
 * 실행 시간 : 508
 * 다익스트라
 */

import java.util.*;

public class Main_B_4485_녹색옷입은애가젤다지_박한성 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int count = 1;

        while (true) {
            int N = scanner.nextInt();
            if (N == 0) {
                break;
            }

            int[][] board = new int[N][N];
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    board[i][j] = scanner.nextInt();
                }
            }

            int[][] dist = new int[N][N];
            boolean[][] visited = new boolean[N][N];
            for (int i = 0; i < N; i++) {
                Arrays.fill(dist[i], 9 * 125 * 125);
            }

            PriorityQueue<Node> pq = new PriorityQueue<>();
            dist[0][0] = board[0][0];
            pq.offer(new Node(0, 0, dist[0][0]));

            int[][] moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            int numVisit = 0;

            while (numVisit < N * N) {
                Node current = pq.poll();
                int y = current.y;
                int x = current.x;

                while (visited[y][x]) {
                    current = pq.poll();
                    y = current.y;
                    x = current.x;
                }

                visited[y][x] = true;
                numVisit++;

                for (int[] move : moves) {
                    int newY = y + move[0];
                    int newX = x + move[1];

                    if (newY < 0 || newY >= N || newX < 0 || newX >= N) {
                        continue;
                    }

                    int newCost = dist[y][x] + board[newY][newX];
                    if (newCost < dist[newY][newX]) {
                        dist[newY][newX] = newCost;
                        pq.offer(new Node(newY, newX, newCost));
                    }
                }
            }

            System.out.println("Problem " + count + ": " + dist[N-1][N-1]);
            count++;
        }
        scanner.close();
    }

    static class Node implements Comparable<Node> {
        int y, x, cost;

        Node(int y, int x, int cost) {
            this.y = y;
            this.x = x;
            this.cost = cost;
        }

        @Override
        public int compareTo(Node other) {
            return Integer.compare(this.cost, other.cost);
        }
    }
}
