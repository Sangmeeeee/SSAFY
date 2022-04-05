package week11.sangmin.problem2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Problem2 {
    static int N, M, R;
    static int[] items;
    static int[][] dist;
    static int INF = 0x1ffffff;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");

        N = Integer.parseInt(line[0]);
        M = Integer.parseInt(line[1]);
        R = Integer.parseInt(line[2]);

        line = br.readLine().split(" ");
        items = new int[N + 1];
        dist = new int[N + 1][N + 1];

        for(int i = 1; i <= N; i++){
            items[i] = Integer.parseInt(line[i - 1]);
        }
        for(int i = 0; i <= N; i++){
            Arrays.fill(dist[i], INF);
            dist[i][i] = 0;
        }

        for(int i = 0; i < R; i++){
            line = br.readLine().split(" ");
            int a = Integer.parseInt(line[0]);
            int b = Integer.parseInt(line[1]);
            int v = Integer.parseInt(line[2]);

            dist[a][b] = v;
            dist[b][a] = v;
        }

        for(int middle = 1; middle <= N; middle++){
            for(int from = 1; from <= N; from++){
                for(int to = 1; to <= N; to++){
                    dist[from][to] = Math.min(dist[from][to], dist[from][middle] + dist[middle][to]);
                }
            }
        }
        int result = Integer.MIN_VALUE;
        for(int i = 1; i <= N; i++){
            int sum = 0;
            for(int j = 1; j <= N; j++){
                    sum += dist[i][j] <= M ? items[j] : 0;
            }
            result = Math.max(result, sum);
        }
        System.out.println(result);
    }
}