package _0823;

/**
 * 메모리 : 22292
 * 실행 시간 : 139
 * 지도상의 각 cell에서 접근가능한 BC를 bitmasking하고
 * 각 시간에 가동할 수 있는 BC를 탐색
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
 
public class Solution_5644_무선충전_박한성 {
    static class BC implements Comparable<BC>{
        int C;
        int P;
        int i;
        int j;
        BC(int c,int p,int i,int j) {C=c;P=p;this.i=i;this.j=j;}
        @Override
        public int compareTo(BC o) {
            return o.P - P; 
        }
    }
    static int dy[] = {0,-1,0,1,0};
    static int dx[] = {0,0,1,0,-1};
     
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
         
        for(int t = 1;t <= T;t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int M = Integer.parseInt(st.nextToken());
            int A = Integer.parseInt(st.nextToken());
            int moveA[] = new int[M];
            int moveB[] = new int[M];
            st = new StringTokenizer(br.readLine());
            for(int i = 0;i < M;i++)  moveA[i] = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            for(int i = 0;i < M;i++)  moveB[i] = Integer.parseInt(st.nextToken());
             
            //Sort BC's list
            List<BC> list = new ArrayList<>();
            for(int i = 0;i < A;i++) {
                st = new StringTokenizer(br.readLine());
                int y = Integer.parseInt(st.nextToken());
                int x = Integer.parseInt(st.nextToken());
                int C = Integer.parseInt(st.nextToken());
                int P = Integer.parseInt(st.nextToken());
                list.add(new BC(C,P,x,y));
            }
            list.sort(null);
             
            //Build bitmap : usability of BC's in cell
            int bitMap[][] = new int[11][11];
            for(int i = 1;i <= 10;i++) {
                for(int j = 1;j <= 10;j++) {
                    for(int bc = 0;bc < A;bc++) {
                        int dist = Math.abs(list.get(bc).i-i) + Math.abs(list.get(bc).j-j);
                        if(dist <= list.get(bc).C) bitMap[i][j] |= (1<<bc);
                    }
                }
            }
             
//          for(int i = 1;i <= 10;i++) {
//              for(int j = 1;j <= 10;j++) {
//                  System.out.print(bitMap[i][j] + " ");
//              }
//              System.out.println();
//          }
             
             
            //calculate
            int Ai = 1;
            int Aj = 1;
            int Bi = 10;
            int Bj = 10;
            int answer = 0;
            for(int day = 0;day <= M;day++) {
                //calculate
                int bit1 = 0;
                if(1 <= Ai && Ai <= 10 && 1 <= Aj && Aj <= 10) bit1 = bitMap[Ai][Aj];
                int bit2 = 0;
                if(1 <= Bi && Bi <= 10 && 1 <= Bj && Bj <= 10) bit2 = bitMap[Bi][Bj];
                 
                 
                //A가 먼저 고르기
                int Achoosed = -1;
                for(int i= 0;i < A;i++) if((bit1 & (1<<i)) > 0) {
                    Achoosed = i; break;
                }
                int Bchoosed = -1;
                for(int i = 0;i < A;i++) if((bit2 & (1<<i)) > 0 && i != Achoosed) {
                    Bchoosed = i; break;
                }
                int case1 = 0;
                if(Achoosed >= 0) case1 += list.get(Achoosed).P;
                if(Bchoosed >= 0) case1 += list.get(Bchoosed).P;
                 
                //B가 먼저 고르기
                Bchoosed = -1;
                for(int i = 0;i < A;i++) if((bit2 & (1<<i)) > 0) {
                    Bchoosed = i; break;
                }
                Achoosed = -1;
                for(int i = 0;i < A;i++) if((bit1 & (1<<i)) > 0 && i != Bchoosed) {
                    Achoosed = i; break;
                }
                int case2 = 0;
                if(Achoosed >= 0) case2 += list.get(Achoosed).P;
                if(Bchoosed >= 0) case2 += list.get(Bchoosed).P;
                 
//              System.out.println("day " + day + " : " + Math.max(case1,case2));
                answer += Math.max(case1,case2);
                 
                if(day < M) {
                    //move
                    Ai += dy[moveA[day]];
                    Aj += dx[moveA[day]];
                    Bi += dy[moveB[day]];
                    Bj += dx[moveB[day]];
                }
            }
             
            //output
            sb.append('#').append(t).append(' ').append(answer).append('\n');
             
        }
        System.out.println(sb.toString());
         
    }
 
}