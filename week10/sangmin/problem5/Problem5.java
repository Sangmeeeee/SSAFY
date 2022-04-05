package week10.sangmin.problem5;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

class Node{
    int y, x;

    public Node(int y, int x) {
        this.y = y;
        this.x = x;
    }
}

public class Problem5 {

    static int[][] map;
    static int[][] value;
    static int[] dx = {0,0,-1,1};
    static int[] dy = {-1,1,0,0};
    static int N, M;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] lines = br.readLine().split(" ");

        N = Integer.parseInt(lines[0]);
        M = Integer.parseInt(lines[1]);

        map = new int[M + 1][N + 1];
        value = new int[M + 1][N + 1];

        for(int i = 1; i <= M; i++){
            String line = br.readLine();
            for(int j = 1; j <= N; j++){
                map[i][j] = line.charAt(j - 1) - '0';
                value[i][j] = 100 * 100 + 1;
            }
        }

        // 1, 1에 도착했을 때 부순 벽의 개수는 0
        value[1][1] = 0;
        Queue<Node> q = new LinkedList<>();

        q.add(new Node(1, 1));
        while (!q.isEmpty()){
            Node curNode = q.poll();

            for(int i = 0; i < 4; i++){
                int nextY = curNode.y + dy[i];
                int nextX = curNode.x + dx[i];

                if(1 <= nextY && nextY <= M && 1 <= nextX && nextX <= N){
                    int dist; // 현재 x, y좌표에서 다음 x, y로 갈때 벽의 개수
                    if(map[nextY][nextX] == 1){ // 다음이 벽이면
                        dist = value[curNode.y][curNode.x] + 1; // 현재 x, y 좌표에서 부순 벽의 개수 + 1
                    }else{
                        dist = value[curNode.y][curNode.x]; // 현재 x, y 좌표에서 부순 벽의 개수
                    }

                    if(value[nextY][nextX] > dist){ // 만약 다음 x, y 좌표의 벽의 개수가 현재 x, y 좌표에서 넘어갔을 때 보다 작을경우 업데이트
                        value[nextY][nextX] = dist;
                        q.add(new Node(nextY, nextX));
                    }
                }
            }
        }
        System.out.println(value[M][N]);
    }
}
