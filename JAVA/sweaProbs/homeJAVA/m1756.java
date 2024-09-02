import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class m1756 {

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int K = sc.nextInt();
		
		
		int selected[] = new int[101];
		int added_day[] = new int[101];
		for(int i = 1;i <= 100;i++) added_day[i] = -1;
		int num_selec = 0;
		for(int k = 0;k < K;k++) {
			int num = sc.nextInt();
			if(selected[num] > 0) selected[num] ++; //just add
			else if (num_selec < N) {
				//on
				 selected[num] ++;
				 added_day[num] = k;
				 num_selec++;
			}
			else {
				//drop lowest one
				int drop = -1;
				int min_rec = Integer.MAX_VALUE;
				for(int i = 1;i <= 100;i++) {
					if(selected[i] == 0) continue;
					if(min_rec > selected[i]) {
						min_rec = selected[i];
						drop = i;
					} else if(min_rec == selected[i] && added_day[drop] > added_day[i]) {
						drop = i;
					}
				}
				//drop i
				added_day[drop] = -1;
				selected[drop] = 0;
				//add num
				selected[num]++;
				added_day[num] = k;
			}
		}
		for(int i = 1;i <= 100;i++) {
			if(selected[i] > 0) System.out.print(i + " ");
		}
	}

}
