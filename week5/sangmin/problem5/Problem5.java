package week5.sangmin.problem5;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

class Node{
    int x,y,value;
    boolean isBreak;

    public Node(int x, int y, int value, boolean isBreak) {
        this.x = x;
        this.y = y;
        this.value = value;
        this.isBreak = isBreak;
    }
}

public class Problem5 {
    static char[][] map = new char[1001][1001];
    static boolean[][][] isVisit = new boolean[2][1001][1001];
    static int N;
    static int M;
    static int min = Integer.MAX_VALUE;

    static int[] dx = {0,0,-1,1};
    static int[] dy = {-1,1,0,0};

    static Queue<Node> q = new LinkedList<>();

    public static void bfs(){
        q.add(new Node(0,0,1,false));
        isVisit[0][0][0] = true;

        while (!q.isEmpty()){
            int curX = q.peek().x;
            int curY = q.peek().y;
            int curValue = q.peek().value;
            boolean curIsBreak = q.poll().isBreak;

            if(curValue > min) continue;
            if(curX == M - 1  && curY == N - 1) {
                min = Math.min(min, curValue);
                return;
            }

            for(int i = 0; i < 4; i++){
                int nextX = curX + dx[i];
                int nextY= curY + dy[i];
                int nextValue = curValue + 1;

                if(0 <= nextX && nextX < M  && 0 <= nextY && nextY < N){
                    if(map[nextY][nextX] == '0'){ // 다음이 그냥 갈 수 있음
                        if(curIsBreak == true){ // 이미 한번 부수고 다음은 벽이 아님
                            if(!isVisit[1][nextY][nextX]){
                                isVisit[1][nextY][nextX] = true;
                                q.add(new Node(nextX, nextY, nextValue, true));
                            }
                        }else{ // 안부수고 다음은 벽이 아님
                            if(!isVisit[0][nextY][nextX]){
                                isVisit[0][nextY][nextX] = true;
                                q.add(new Node(nextX, nextY, nextValue, false));
                            }
                        }
                    }else{ // 다음이 벽임
                        if(curIsBreak == false){ // 다음이 벽이고 벽을 부수지 않음
                            if(!isVisit[1][nextY][nextX]){
                                isVisit[1][nextY][nextX] = true;
                                q.add(new Node(nextX, nextY, nextValue, true));
                            }
                        }
                    }
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        N = Integer.parseInt(line[0]);
        M = Integer.parseInt(line[1]);

        for(int i = 0; i < N; i++){
            map[i] = br.readLine().toCharArray();
        }
        bfs();
        System.out.println(min == Integer.MAX_VALUE ? -1 : min);
    }
}
