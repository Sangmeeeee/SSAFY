package week11.sangmin.problem5;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Problem5 {
    static int[][] dist;
    static int[][] calDist;
    static boolean[][] isUse;
    static int N;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        dist = new int[N][N];
        isUse = new boolean[N][N];
        calDist = new int[N][N];

        for(int i = 0; i < N; i++){
            String[] line = br.readLine().split(" ");
            for(int j = 0; j < N; j++){
                dist[i][j] = Integer.parseInt(line[j]);
                calDist[i][j] = dist[i][j];
            }
        }

        for(int middle = 0; middle < N; middle++) {
            for (int from = 0; from < N; from++) {
                for (int to = 0; to < N; to++) {
                    // from = 1, to = 2, middle 2와 같은 상황이면 무조건 dist[from][to] == dist[from][middle] + dist[middle][to]가 true기 때문에 넘어가야함
                    // 또한, 0 -> 0 -> 0과 같은 쓸데없는 연산을 하지 않기 위해
                    if(from == middle || middle == to || from == to) continue;
                    if(dist[from][to] != Math.min(dist[from][to], dist[from][middle] + dist[middle][to])){
                        System.out.println(-1);
                        return;
                    }
                    if(dist[from][to] == dist[from][middle] + dist[middle][to]){
                        calDist[from][to] = -1;
                    }
                }
            }
        }

        int result = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(!isUse[i][j]) {
                    result += calDist[i][j] == -1 ? 0 : calDist[i][j];
                    isUse[i][j] = true;
                    isUse[j][i] = true;
                }
            }
        }
        System.out.println(result);

    }
}

/*
5
0 6 15 2 6
6 0 9 8 12
15 9 0 16 18
2 8 16 0 4
6 12 18 4 0

3
0 1 3
1 0 1
3 1 0
 */
