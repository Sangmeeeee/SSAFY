package week11.sangmin.problem3;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Node{
    int type, x, y;

    public Node(int type, int x, int y) {
        this.type = type;
        this.x = x;
        this.y = y;
    }
}

public class Problem3 {
    static int N, T;
    static int M;
    static Node[] nodes;
    static int[][] dist;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        N = Integer.parseInt(line[0]);
        T = Integer.parseInt(line[1]);

        nodes = new Node[N + 1];
        dist = new int[N + 1][N + 1];
        for(int i = 1; i <= N; i++){
            line = br.readLine().split(" ");
            nodes[i] = new Node(Integer.parseInt(line[0]), Integer.parseInt(line[1]), Integer.parseInt(line[2]));
        }

        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(nodes[i].type == 1 && nodes[j].type == 1) {
                    dist[i][j] = Math.min(Math.abs(nodes[i].x - nodes[j].x) + Math.abs(nodes[i].y - nodes[j].y), T);
                }else{
                    dist[i][j] = Math.abs(nodes[i].x - nodes[j].x) + Math.abs(nodes[i].y - nodes[j].y);
                }
            }
        }

        for(int middle = 1; middle <= N; middle++){
            for(int from = 1; from <= N; from++){
                for(int to = 1; to <= N; to++){
                    dist[from][to] = Math.min(dist[from][to], dist[from][middle] + dist[middle][to]);
                }
            }
        }
        M = Integer.parseInt(br.readLine());
        for(int i = 0; i < M; i++){
            line = br.readLine().split(" ");
            System.out.println(dist[Integer.parseInt(line[0])][Integer.parseInt(line[1])]);
        }
    }
}
/*
6 3
0 1 2
0 5 1
1 3 3
1 1 5
0 3 5
1 7 5
5
1 2
1 5
1 6
3 4
4 2


 */