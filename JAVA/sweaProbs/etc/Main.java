package day0910;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class A형 {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine().trim());

        for (int t = 1; t <= T; t++) {
            int N = Integer.parseInt(br.readLine().trim());

            List<Integer> adj[] = new ArrayList[N + 1];
            for (int i = 0; i < N + 1; i++) {
                adj[i] = new ArrayList<>();
            }

            int arr[] = new int[N + 1];
            for (int i = 1; i <= N; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine().trim());
                arr[i] = Integer.parseInt(st.nextToken());
                for (int j = 0; j < arr[i]; j++) {
                    int num = Integer.parseInt(st.nextToken());
                    adj[num].add(i);
                }
            }
            // input end

//            int z = 0;
//            for (List<Integer> a : adj) {
//                System.out.println("adj "+ z++);
//                for (int i = 0; i < a.size(); i++) {
//                    System.out.print(a.get(i) + " ");
//                }
//                System.out.println(" adj size " + a.size());
//            }

            int answer = 0;
            int cnt = 0;
            int add = 0;
            while (true) {
                List<Integer> tmp = new ArrayList<>();
                boolean flag = false;
                for (int i = 1; i < N + 1; i++) {
                    if (arr[i] == 0) {
                        for (int j = 0; j < adj[i].size(); j++) {
                            int num = adj[i].get(j);
//                            System.out.println("num " + num);
                            tmp.add(num);
                        }
                        arr[i] = -1;
                        cnt++;
                        flag = true;
//                        System.out.println("true");
//                        System.out.println(Arrays.toString(arr));
                    }
                }
//                for (Integer a : tmp) {
//                    System.out.print(a + " ");
//                }
                if (!flag) {
                    answer = -1;
                    break;
                }
                for (int i = 0; i < tmp.size(); i++) {
                    arr[tmp.get(i)]--;
                }
                answer++;
                if (cnt == N) {
                    break;
                }
            }
            sb.append("#").append(t).append(" ").append(answer).append('\n');
        }
        System.out.println(sb);
    }
}