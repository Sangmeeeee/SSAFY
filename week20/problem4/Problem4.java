package week20.sangmin.problem4;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {

    static final int INF = 10000;
    int dp[][] = new int[201][101];
    List<List<Integer>> list = new ArrayList<>();

    public int solution(int n, int m, int[][] edge_list, int k, int[] gps_log) {
        for(int i = 0; i <= n; i++){
            list.add(new ArrayList<>());
            Arrays.fill(dp[i], INF);
        }

        for(int i = 0; i < edge_list.length; i++){
            list.get(edge_list[i][0]).add(edge_list[i][1]);
            list.get(edge_list[i][0]).add(edge_list[i][0]);
            list.get(edge_list[i][1]).add(edge_list[i][0]);
            list.get(edge_list[i][1]).add(edge_list[i][1]);
        }

        dp[gps_log[0]][0] = 0;

        for(int idx = 1; idx < k - 1; idx++){
            for(int target = 1; target <= n; target++){
                for(int num : list.get(target)){
                    if(dp[num][idx - 1] != INF){
                        dp[target][idx] = target == gps_log[idx] ? Math.min(dp[target][idx], dp[num][idx - 1]) : Math.min(dp[target][idx], dp[num][idx - 1] + 1);
                    }
                }
            }
        }

        for(int num : list.get(gps_log[k - 1])){
            if(dp[num][k - 2] != INF) {
                dp[gps_log[k - 1]][k - 1] = Math.min(dp[gps_log[k - 1]][k - 1], dp[num][k - 2]);
            }
        }

        return dp[gps_log[k - 1]][k - 1] == INF ? -1 : dp[gps_log[k - 1]][k - 1];
    }
}

public class Problem4 {
    public static void main(String[] args) {
        new Solution().solution(7, 10, new int[][]{{1, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 4}, {3, 5}, {4, 6}, {5, 6}, {5, 7}, {6, 7}}, 6, new int[]{1, 2, 3, 3, 6, 7});
//        new Solution().solution(7, 10, new int[][]{{1, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 4}, {3, 5}, {4, 6}, {5, 6}, {5, 7}, {6, 7}}, 6, new int[]{1, 2, 4, 6, 5, 7});
//        new Solution().solution(7, 10, new int[][]{{1, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 4}, {3, 5}, {4, 6}, {5, 6}, {5, 7}, {6, 7}}, 2, new int[]{1, 7});
//        new Solution().solution(7, 10, new int[][]{{1, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 4}, {3, 5}, {4, 6}, {5, 6}, {5, 7}, {6, 7}}, 3, new int[]{1, 2, 6});
//        new Solution().solution(7, 10, new int[][]{{1, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 4}, {3, 5}, {4, 6}, {5, 6}, {5, 7}, {6, 7}}, 4, new int[]{1, 1, 1, 7});
    }
}
