package week11.sangmin.problem4;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Problem4 {
    static int N, M;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] line = br.readLine().split(" ");
        N = Integer.parseInt(line[0]);
        M = Integer.parseInt(line[1]);

        int[][] dist = new int[N + 1][N + 1];
        for(int i = 0; i <= N; i++){
            Arrays.fill(dist[i], 10000);
            dist[i][i] = 0;
        }

        for(int i = 0; i < M; i++){
            line = br.readLine().split(" ");
            int A = Integer.parseInt(line[0]);
            int B = Integer.parseInt(line[1]);

            dist[A][B] = 1;
            dist[B][A] = 1;
        }

        for(int middle = 1; middle <= N; middle++){
            for(int from = 1; from <= N; from++) {
                for (int to = 1; to <= N; to++) {
                    dist[from][to] = Math.min(dist[from][to], dist[from][middle] + dist[middle][to]);
                }
            }
        }
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                dist[i][j] *= 2;
            }
        }
        int result = Integer.MAX_VALUE;
        int num1 = 0;
        int num2 = 0;
        for(int i = 1; i <= N; i++){
            for(int j = i + 1; j <= N; j++){

                int sum = 0;
                for(int k = 1; k <= N; k++){
                    sum += Math.min(dist[k][i], dist[k][j]);
                }
                if(result > sum){
                    num1 = i;
                    num2 = j;
                    result = sum;
                }
            }
        }
        System.out.println(num1 + " " + num2 + " " + result);
    }
}
