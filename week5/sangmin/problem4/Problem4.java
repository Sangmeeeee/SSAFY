package week5.sangmin.problem4;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

class Squirrel{
    int y,x,time;

    public Squirrel(int y, int x, int time) {
        this.y = y;
        this.x = x;
        this.time = time;
    }
}

public class Problem4 {
    static char[][][] map = new char[251][50][50];
    static boolean[][] visitMap = new boolean[50][50];

    static boolean[] isVisit = new boolean[251];
    static int R, C;

    static int[] dx = {0,0,-1,1};
    static int[] dy = {-1,1,0,0};

    static int targetX, targetY;

    static int min = Integer.MAX_VALUE;

    static Queue<Squirrel> q = new LinkedList<>();

    static void makeMap(int curTime){
        int beforeTime = curTime - 1;
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                if(map[beforeTime][i][j] == '*'){
                    map[curTime][i][j] = '*';

                    for(int k = 0; k < 4; k++){
                        int nextX = j + dx[k];
                        int nextY = i + dy[k];
                        if(0 <= nextX && nextX < C && 0 <= nextY && nextY < R &&
                                map[0][nextY][nextX] != 'D' && map[0][nextY][nextX] != 'X'){
                            map[curTime][nextY][nextX] = '*';
                        }
                    }
                }
            }
        }
    }

    static void bfs(){
        isVisit[0] = true;

        while(!q.isEmpty()){
            Squirrel curSquirrel = q.poll();

            if(curSquirrel.x == targetX && curSquirrel.y == targetY){
                min = Math.min(curSquirrel.time, min);
            }

            for(int i = 0; i < 4; i++){
                int nextX = curSquirrel.x + dx[i];
                int nextY = curSquirrel.y + dy[i];
                int nextTime = curSquirrel.time + 1;

                if(!isVisit[nextTime]){
                    isVisit[nextTime] = true;
                    makeMap(nextTime);
                }

                if(0 <= nextX && nextX < C && 0 <= nextY && nextY < R &&
                        !visitMap[nextY][nextX] && map[nextTime][nextY][nextX] != '*' &&
                        map[0][nextY][nextX] != 'X'){
                    // 갈 수 있고, 물이 아니고, 방문하지 않은 노드일경우
                    visitMap[nextY][nextX] = true;
                    q.add(new Squirrel(nextY, nextX, nextTime));
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] line = br.readLine().split(" ");

        R = Integer.parseInt(line[0]);
        C = Integer.parseInt(line[1]);

        for(int i = 0; i < R; i++){
            map[0][i] = br.readLine().toCharArray();
            for(int j = 0; j < C; j++){
                if(map[0][i][j] == 'D'){
                    targetX = j;
                    targetY = i;
                }
                if(map[0][i][j] == 'S'){
                    q.add(new Squirrel(i,j,0));
                }
            }
        }
        bfs();
        System.out.println(min == Integer.MAX_VALUE ? "KAKTUS" : min);
    }
}

/*
3 3
S..
.D.
...

5 7
S....X*
.XXX.X.
..X..X.
X.X.XX.
X...DX.

 */