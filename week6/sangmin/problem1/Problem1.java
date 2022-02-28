package week6.sangmin.problem1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Problem1 {
    static int[][] map = new int[20][20];
    static int N,M;
    static int x,y;
    static int K;
    static int[] dx = {1,-1,0,0}; // 동 서 북 남
    static int[] dy = {0,0,-1,1};
    static StringBuilder sb = new StringBuilder();

    static class Dice{
        int left, right, up, down, top, bottom;

        void moveDice(int direction){
            int nextX = x + dx[direction - 1];
            int nextY = y + dy[direction - 1];
            if(0 <= nextX && nextX < M && 0 <= nextY && nextY < N){
                y = nextY;
                x = nextX;
                rotateDice(direction);
            }
        }

        void rotateDice(int direction) {
            //회전 하고 바닥 지정
            int temp;
            switch (direction) {
                case 1: temp = this.top; // 동
                    this.top = this.left;
                    this.left = this.bottom;
                    this.bottom = this.right;
                    this.right = temp;
                    break;
                case 2:  temp = this.top;// 서
                    this.top = this.right;
                    this.right = this.bottom;
                    this.bottom = this.left;
                    this.left = temp;
                    break;
                case 3: temp = this.top;// 북
                    this.top = this.down;
                    this.down = this.bottom;
                    this.bottom = this.up;
                    this.up = temp;
                    break;
                case 4: temp = this.top; // 남
                    this.top = this.up;
                    this.up = this.bottom;
                    this.bottom = this.down;
                    this.down = temp;
                    break;
            }
            if(map[y][x] == 0){
                map[y][x] = this.bottom;
            }else{
                this.bottom = map[y][x];
                map[y][x] = 0;
            }
            sb.append(this.top + "\n");
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        N = Integer.parseInt(line[0]);
        M = Integer.parseInt(line[1]);
        y = Integer.parseInt(line[2]);
        x = Integer.parseInt(line[3]);
        K = Integer.parseInt(line[4]);
        for(int i = 0; i < N; i++){
            line = br.readLine().split(" ");
            for(int j = 0; j < M; j++){
                map[i][j] = Integer.parseInt(line[j]);
            }
        }
        Dice dice = new Dice();
        line = br.readLine().split(" ");
        for(String command : line){
            dice.moveDice(Integer.parseInt(command));
        }
        System.out.print(sb.toString());
    }
}
