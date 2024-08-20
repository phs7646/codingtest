package _0820;

/**
 * 메모리 : 21492
 * 실행 시간 : 149
 * dfs
 */

import java.util.*;

public class Solution_1486_장훈이의높은선반_박한성 {

    private static final int BIGNUM = 200007;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();
        for (int t = 1; t <= T; t++) {
            int N = sc.nextInt();
            int B = sc.nextInt();
            int sum = 0;
            int[] v = new int[N];
            int[] accum = new int[N];

            for (int i = 0; i < N; i++) {
                v[i] = sc.nextInt();
                sum += v[i];
            }

            Arrays.sort(v);
            reverseArray(v);

            accum[N - 1] = v[N - 1];
            for (int i = N - 2; i >= 0; i--) {
                accum[i] = accum[i + 1] + v[i];
            }

            int answer = sum;
            for (int i = 0; i < N; i++) {
                if (sum < B) break;
                answer = Math.min(answer, v[i] + dfs(v, accum, i + 1, B - v[i]));
                sum -= v[i];
            }

            System.out.println("#" + t + " " + (answer - B));
        }

        sc.close();
    }

    private static int dfs(int[] v, int[] accum, int i, int val) {
        if (val <= 0) return 0;
        if (i >= v.length) return BIGNUM;
        if (accum[i] < val) return BIGNUM;
        if (accum[i] == val) return val;
        return Math.min(dfs(v, accum, i + 1, val), v[i] + dfs(v, accum, i + 1, val - v[i]));
    }

    private static void reverseArray(int[] array) {
        int left = 0, right = array.length - 1;
        while (left < right) {
            int temp = array[left];
            array[left] = array[right];
            array[right] = temp;
            left++;
            right--;
        }
    }
}
