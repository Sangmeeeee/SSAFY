package week9.sangmin.extra.problem7;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Problem7 {
    static int[][] map;
    static int[][] dp;
    static int T;
    static int N;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        T = Integer.parseInt(br.readLine());
        while (T-- > 0){
            N = Integer.parseInt(br.readLine());
            map = new int[2][N + 1];
            dp = new int[2][N + 1];
            for(int i = 0; i < 2; i++){
                String[] line = br.readLine().split(" ");
                for(int j = 1; j <= N; j++){
                    map[i][j] = Integer.parseInt(line[j - 1]);
                }
            }
            dp[0][1] = map[0][1];
            dp[1][1] = map[1][1];

            for(int i = 2; i <= N; i++){
                dp[1][i] = Math.max(dp[0][i-2], dp[0][i - 1]) + map[1][i];
                dp[0][i] = Math.max(dp[1][i-2], dp[1][i - 1]) + map[0][i];
            }
            System.out.println(Math.max(dp[1][N], dp[0][N]));
        }
    }
}
