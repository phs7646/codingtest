import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    static class Edge implements Comparable<Edge> {
        int city;
        int cost;
        Edge(int b, int c) {city = b; cost = c;}
        @Override
        public int compareTo(Edge o) {
            return Integer.compare(cost, o.cost);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();

        List<Edge> adj[] = new List[N + 1];
        for (int i = 1; i <= N; i++) adj[i] = new ArrayList<>();

        for (int i = 0; i < M; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();
            // a->b c비용
            adj[a].add(new Edge(b, c));
        }

        int startCity = sc.nextInt();
        int endCity = sc.nextInt();

        /* 다익스트라 시작!!!! */

        // dist 배열 만들기
        int dist[] = new int[N + 1];
        for (int i = 1; i <= N; i++) dist[i] = Integer.MAX_VALUE;
        boolean visited[] = new boolean[N + 1];
        PriorityQueue<Edge> pq = new PriorityQueue<>();

        dist[startCity] = 0;
        pq.add(new Edge(startCity, 0));

        while (!pq.isEmpty()) {
            // 방문할 정점 선정하기
            Edge e = pq.poll();

            if (visited[e.city]) continue;

            // 진짜 방문함 이제
            visited[e.city] = true; // 맨 처음엔 startCity

            // 업데이트 e.city에서 갈 수 있는 모든 곳을
            for (Edge nextEdge : adj[e.city]) {
                if (!visited[nextEdge.city]) {
                    int newCost = dist[e.city] + nextEdge.cost;
                    if (dist[nextEdge.city] > newCost) {
                        // 업데이트해야됨
                        dist[nextEdge.city] = newCost;
                        pq.add(new Edge(nextEdge.city, newCost));
                    }
                }
            }
        }

        // 다익스트라 끝!
        System.out.println(dist[endCity]);
    }
}
