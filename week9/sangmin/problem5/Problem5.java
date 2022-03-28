package week9.sangmin.problem5;

import java.util.Scanner;

public class Problem5 {
    static int[][] dp = new int[31][2];
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[1][0] = 0;
        dp[1][1] = 0;
        dp[2][0] = 3;
        dp[2][1] = 0;

        for(int i = 4; i <= N; i++){
            if(i % 2 == 0) {
                for (int j = 0; i - j >= 4; j++) {
                    dp[i][1] += dp[j][0];
                }
                dp[i][1]++;
            }
            dp[i][0] = dp[i][1] * 2 + dp[i - 2][0] * 3;
        }
        System.out.println(dp[N][0]);
    }
}
