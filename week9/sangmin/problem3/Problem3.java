package week9.sangmin.problem3;

import java.util.Scanner;

public class Problem3 {
    static long[][] dp;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        dp = new long[2][1000001];
        dp[0][0] = 0; dp[1][0] = 0;
        dp[0][1] = 2; dp[1][1] = 1;
        dp[0][2] = 7; dp[1][2] = 1; // ㄴ자로 튀어나옴
        for(int i = 3; i <= N; i++){
            dp[1][i] = (dp[0][i - 3] + dp[1][i - 1]) % 1000000007;
            dp[0][i] = (dp[1][i] * 2 + dp[0][i - 1] * 2 + dp[0][i - 2] * 3) % 1000000007;
        }
        System.out.println(dp[0][N]);
    }
}
