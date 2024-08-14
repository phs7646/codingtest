package _0814;

/**
 * 메모리 : 14204
 * 실행 시간 : 96
 * 2개를 골라서 sum-100 만들기
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_B_3040_백설공주와일곱난쟁이_박한성 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int arr[] = new int[9];
		int sum = 0;
		for(int i = 0;i < 9;i++) {
			arr[i] = Integer.parseInt(br.readLine().trim());
			sum += arr[i];
		}
		int target = sum-100;
		int a=-1,b=-1;
		label : for(int i = 0;i < 9;i++) {
			for(int j = i+1;j < 9;j++) {
				if(arr[i] + arr[j] == target) {
					a = i; b = j;
					break label;
				}
			}
		}
		for(int i = 0;i < 9;i++) if(i != a && i != b) System.out.println(arr[i]);

	}

}
