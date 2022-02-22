package week4.sangmin.problem1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Problem1 {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] firstLine = br.readLine().split(" ");
        int N = Integer.parseInt(firstLine[0]);
        int H = Integer.parseInt(firstLine[1]);
        int[][] count = new int[H + 2][2]; // 석순 = 0, 종유석 = 1

        for (int i = 0; i < N / 2; i++) {
            int num = Integer.parseInt(br.readLine());
            count[num][0]++;
            num = Integer.parseInt(br.readLine());
            count[num][1]++;
        }

        for(int i = H; i >= 1; i--) {
            count[i - 1][0] += count[i][0];
            count[i - 1][1] += count[i][1];
        }

        int min = Integer.MAX_VALUE;
        int minCount = 0;
        for(int i = 1; i <= H; i++) {
            int sum = count[i][0] + count[H - i + 1][1];
            if(sum < min) {
                min = sum;
                minCount = 1;
            }else if(min == sum) {
                minCount++;
            }
        }
        System.out.println(min + " " + minCount);
    }
}
