package week9.sangmin.problem2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Problem2 {
    static int[][] dp = new int[1001][1001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String first = br.readLine();
        String second = br.readLine();

        for(int i = 0; i < first.length(); i++){
            for(int j = 0; j < second.length(); j++){
                if(first.charAt(i) == second.charAt(j)){
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                }else{
                    dp[i + 1][j + 1] = Math.max(dp[i][j + 1], dp[i+1][j]);
                }
            }
        }

        System.out.println(dp[first.length()][second.length()]);
    }
}

/*
ABAABA
AA

AA
ABAABA
 */