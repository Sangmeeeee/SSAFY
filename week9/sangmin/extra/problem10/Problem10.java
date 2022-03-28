package week9.sangmin.extra.problem10;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Problem10 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine().trim());
        int[][] map = new int[N + 1][3]; // r g b
        int[][] dp = new int[N + 1][3];

        int result = Integer.MAX_VALUE;

        for(int i = 1; i <= N; i++){
            String[] line = br.readLine().split(" ");
            map[i][0] = Integer.parseInt(line[0]);
            map[i][1] = Integer.parseInt(line[1]);
            map[i][2] = Integer.parseInt(line[2]);
        }

        for(int color = 0; color < 3; color++){ // r g b
            for(int i = 0; i < 3; i++){
                dp[1][i] = i == color ? map[1][i] : (1000 * 1000 + 1);
            }

            for(int i = 2; i <= N; i++){
                dp[i][0] = Math.min(dp[i-1][1], dp[i-1][2]) + map[i][0];
                dp[i][1] = Math.min(dp[i-1][0], dp[i-1][2]) + map[i][1];
                dp[i][2] = Math.min(dp[i-1][0], dp[i-1][1]) + map[i][2];
            }

            for(int i = 0; i < 3; i++){
                result = i != color ? Math.min(result, dp[N][i]) : result;
            }
        }
        System.out.println(result);
    }
}
