package week21.sangmin.problem1;

class Solution {
    int MOD = 20170805;

    public int solution(int m, int n, int[][] map) {
        int[][] cityMap = new int[m + 2][n + 2];
        int dp[][][] = new int[2][502][502]; // 0 = 위, 1 = 오른쪽

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                cityMap[i][j] = map[i-1][j-1];
            }
        }
        dp[0][1][1] = 1;
        dp[1][1][1] = 1;

        for(int i = 1; i <= m; i++){
            for(int x = i; x <= n; x++){
                if(cityMap[i][x] == 1) continue;

                if(cityMap[i][x] == 2){
                    dp[0][i][x] += dp[0][i - 1][x];
                    dp[1][i][x] += dp[1][i][x - 1];
                }else if(cityMap[i][x] == 0){
                    dp[0][i][x] += dp[1][i][x - 1] + dp[0][i - 1][x];
                    dp[1][i][x] += dp[1][i][x - 1] + dp[0][i - 1][x];
                }

                dp[0][i][x] %= MOD;
                dp[1][i][x] %= MOD;
            }

            for(int y = i + 1; y <= m; y++){
                if(cityMap[y][i] == 1) continue;

                if(cityMap[y][i] == 2){
                    dp[0][y][i] += dp[0][y - 1][i];
                    dp[1][y][i] += dp[1][y][i - 1];
                }else if(cityMap[y][i] == 0){
                    dp[0][y][i] += dp[1][y][i - 1] + dp[0][y - 1][i];
                    dp[1][y][i] += dp[1][y][i - 1] + dp[0][y - 1][i];
                }

                dp[0][y][i] %= MOD;
                dp[1][y][i] %= MOD;
            }
        }
        return (dp[0][m][n] + dp[1][m][n]) / 2;
    }
}

public class Problem1 {
    public static void main(String[] args) {
        new Solution().solution(3, 3, new int[3][3]);
    }
}
