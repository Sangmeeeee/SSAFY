package week9.inseok.Problem1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Problem1 {
    public static void main(String[] args) throws IOException {
        BufferedReader br  = new BufferedReader(new InputStreamReader(System.in));
        String A;
        String B;
        int [][] dp;
        A = br.readLine();
        B = br. readLine();
        dp = new int[A.length()+1][B.length()+1];

        //sol
        for (int i = 1; i <= A.length(); i++) {
            for (int j = 1; j <= B.length(); j++) {
                //같으면 그전 행에서 max 들중 + 1
                if(A.charAt(i-1)==B.charAt(j-1)){
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        //answer
        System.out.println(dp[A.length()][B.length()]);
    }
}
//https://www.acmicpc.net/problem/9251
//LCS