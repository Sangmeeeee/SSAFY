package week11.sangmin.problem1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Problem1 {
    static int N, M;
    static int[][] dist;
    static int INF = 10000 * 10000 + 1;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        N = Integer.parseInt(line[0]);
        dist = new int[N + 1][N + 1];
        line = br.readLine().split(" ");
        M = Integer.parseInt(line[0]);

        for(int i = 0; i <= N; i++){
            for(int j = 0; j <= N; j++){
                dist[i][j] = i == j ? 0 : INF;
            }
        }

        for(int i = 0; i < M; i++){
            line = br.readLine().split(" ");
            int a = Integer.parseInt(line[0]);
            int b = Integer.parseInt(line[1]);
            int c = Integer.parseInt(line[2]);

            dist[a][b] = Math.min(dist[a][b], c);
        }

        for(int mid = 1; mid <= N; mid++){
            for(int from = 1; from <= N; from++){
                for(int to = 1; to <= N; to++){
                    dist[from][to] = Math.min(dist[from][to], dist[from][mid] + dist[mid][to]);
                }
            }
        }

        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                System.out.print((dist[i][j] == INF ? 0 : dist[i][j]) + " ");
            }
            System.out.println();
        }
    }
}
