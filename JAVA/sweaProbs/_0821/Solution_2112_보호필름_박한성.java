package _0821;

/**
 * 메모리 : 38660
 * 실행 시간 : 550
 * 비트마스킹으로 완전탐색
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
 
public class Solution_2112_보호필름_박한성 {
     
    static int D, W, K;
    static List<Integer> answerBits;
    static int[] originalBit;
    static StringBuilder sb;
     
    static boolean isBitOK(int bit) {
        // 해당 bit가 answerBits 중 하나라도 포함하면 true
        for(int answer : answerBits) {
            if((bit & answer) == answer) return true;
        }
        return false;
    }
     
    static int applyMask(int original, int change_bit, int case_bit) {
        int zeroMasking = ~0;
        int oneMasking = 0;
        int count = 0;
        for(int j = 0; j < D; j++) {
            if((change_bit & (1 << j)) > 0) {
                if((case_bit & (1 << count)) > 0) {
                    // 해당 비트를 1로 마스킹
                    oneMasking |= 1 << j;
                } else {
                    // 해당 비트를 0으로 마스킹
                    zeroMasking &= ~(1 << j);
                }
                count++;
            }
        }
        return (original & zeroMasking) | oneMasking;
    }
     
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine().trim());
        label: for(int t = 1; t <= T; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            D = Integer.parseInt(st.nextToken());
            W = Integer.parseInt(st.nextToken());
            K = Integer.parseInt(st.nextToken());
             
            // answerBits 만들기
            answerBits = new ArrayList<>();
            // K개가 연속된 비트들의 모음
            int answerbit = (1 << K) - 1;
            for(int i = 0; i <= D - K; i++) {
                answerBits.add(answerbit);
                answerbit <<= 1;
            }
             
            // originalBit 입력받기
            originalBit = new int[W];
            for(int i = 0; i < D; i++) {
                st = new StringTokenizer(br.readLine());
                for(int j = 0; j < W; j++) {
                    int b = Integer.parseInt(st.nextToken());
                    if(b == 1) originalBit[j] |= (1 << i);
                }
            }
 
            // 검사 대상 비트 만들기
            List<Integer>[] changes = new List[D+1];
            for(int i = 0; i <= D; i++) changes[i] = new ArrayList<>();
            int max_bit = (1 << D) - 1; // 1...1 D개
            for(int bit = 0; bit <= max_bit; bit++) {
                // 현재 bit가 변화하는 대상 갯수 세기
                int count = Integer.bitCount(bit);
                // changes[count]에 추가
                changes[count].add(bit);
            }
             
            // 0개 바꾸는 것부터 검사하기
            for(int num_change = 0; num_change <= D; num_change++) {
                // 약품을 묻히는 비트 선정. 각 비트를 1로 묻힐 수도 있고, 0으로 묻힐 수도 있음
                for(int change_bit : changes[num_change]) {
                    // 각 비트를 0으로 masking하거나 1로 masking할 수 있음
                    int max_case = (1 << num_change);
                    for(int case_bit = 0; case_bit < max_case; case_bit++) {
                        // 모든 열에 대해 검사
                        boolean flag = true;
                        for(int j = 0; j < W; j++) {
                            int bit = applyMask(originalBit[j], change_bit, case_bit);
                            int bit2 = bit ^ ((1<<D)-1); //flip
                            if(!isBitOK(bit) && !isBitOK(bit2)) {
                                flag = false;
                                break;
                            }
                        }
                        if(flag) {
                            // 조건을 만족하는 최소 변경 횟수 찾음
                            sb.append('#').append(t).append(' ').append(num_change).append('\n');
                            continue label;
                        }
                    }
                }
            }
             
            // 모든 비트를 바꿔야 하는 경우
            sb.append('#').append(t).append(' ').append(D).append('\n');
        }
        System.out.println(sb);
    }
}