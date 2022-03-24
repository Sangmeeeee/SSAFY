package week9.sangmin.problem4;

import java.util.Scanner;

public class Problem4 {
    static long[][] dp = new long[1001][1001];
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();

        for(int i = 1; i <= N; i++) {
            dp[i][1] = i;
        }

        for(int i = 2; i <= K; i++) {
            for(int j = 3; j <= N; j++) {
                dp[j][i] = (dp[j - 2][i - 1] + dp[j - 1][i]) % 1000000003;
            }
        }
        if(K == 1){
            System.out.println(N);
        }else {
            System.out.println((dp[N - 3][K - 1] + dp[N - 1][K]) % 1000000003);
        }
    }
}