package week9.sangmin.extra.problem8;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Problem8 {
    static int N,K;
    static int[] V;
    static int[] W;
    static int[][] dp;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        N = Integer.parseInt(line[0]);
        K = Integer.parseInt(line[1]);
        V = new int[N + 1];
        W = new int[N + 1];
        dp = new int[N + 1][K + 1]; // w, v;

        for(int i = 1; i <= N; i++){
            line = br.readLine().split(" ");
            W[i] = Integer.parseInt(line[0]);
            V[i] = Integer.parseInt(line[1]);
        }

        for(int w = 1; w <= K; w++) {
            for (int i = 1; i <= N; i++) {
                if(W[i] > w){
                    dp[i][w] = dp[i-1][w];
                }else{
                    dp[i][w] =  Math.max(dp[i-1][w], dp[i-1][w - W[i]] + V[i]);
                }
            }
        }
        System.out.println(dp[N][K]);
    }
}
