package week9.inseok.Problem3;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Problem3 {
    public static void main(String[] args) throws IOException {
        int N;
        long [][] dp;
        long MOD=1000000007;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        dp = new long[3][N];
        dp[0][0]=1;
        dp[1][0]=2;
        dp[2][0]=1;
        if(2<=N){
            dp[0][1]=3;
            dp[1][1]=7;
            dp[2][1]=3;
        }
        for(int i=2;i<N;i++){
            dp[0][i]=(dp[1][i-1] + dp[2][i-1])%MOD;
            dp[1][i]=(dp[0][i-1] + 2* dp[1][i-1] + dp[2][i-1] + dp[1][i-2])%MOD;
            dp[2][i]=(dp[1][i-1] + dp[0][i-1])%MOD;
        }
        System.out.println(dp[1][N-1]);
    }
}
