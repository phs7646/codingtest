package _0828;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
/*
 * 인접행렬 101x101 boolean
 * i->j true로 만들기
 * 그렇담  bfs 는 안되는거같고 dfs
 * dfs 매개변수로 depth를 더함
 * 이제 dfs(시작지점)해서 for문 100개 다 돌았는데 갈데가 없다 ? 그럼 이제 depth가 되는거임
 * depth가 최대일때 번호 큰사람 저장
 */
public class etc {
    static int n;
    static boolean adj[][];
    static StringBuilder sb;
    static boolean visited[];
    static int list[];
    /*
     * list에 최소거리만 저장할거임 처음에 초기화 어케함 ? list[y]가 0이면 해당 depth로 하면 되겠지 그다음에 값이 있다면 ?
     * 해당 list 보다 depth가 작다면 depth 저장하고 킵고잉 ~~ 그치만 해당 list보다 값이 크다면 ? return ~~
     */
    static void dfs(int y, int depth) {
        if (list[y] == 0 || list[y]>=depth)
            list[y] = depth;
        else return;
		visited[y] = true;
        for (int i = 1; i <= 100; i++) {
            if (visited[i])
                continue;
            if (adj[y][i]) {
                dfs(i, depth + 1);
            }
        }
		visited[y] = false;
    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        sb = new StringBuilder();
        for (int t = 1; t <= 10; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine().trim());
            int n = Integer.parseInt(st.nextToken()); // 데이터의 길이
            int start = Integer.parseInt(st.nextToken()); // 시작점
            adj = new boolean[101][101];
            visited = new boolean[101];
            st = new StringTokenizer(br.readLine().trim());
            for (int i = 0; i < n / 2; i++) {
                int y = Integer.parseInt(st.nextToken());
                int x = Integer.parseInt(st.nextToken());
                adj[y][x] = true; // y에서 x로 가면 true
            }
            // input end
            int max_count = 0;
            int person = start;
            list = new int[101];
            dfs(start, 1);
            
            
            
            for(int i = 1; i<=100; i++) {
//                System.out.println(i+" "+list[i]);
                
                if(max_count < list[i]) {
                    max_count = list[i];
                    person = i;
                }
                else if(max_count == list[i]) {
                    person = Math.max(person, i);
                }
            }
            
            sb.append("#").append(t).append(' ').append(person).append('\n');
        }
        System.out.println(sb);
    }
}