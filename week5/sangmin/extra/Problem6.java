package week5.sangmin.extra.problem6;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Node{
    int y,x,z,days;

    public Node(int y, int x, int z, int days) {
        this.y = y;
        this.x = x;
        this.z = z;
        this.days = days;
    }
}

public class Problem6 {

    static int[][][] map = new int[101][101][101];
    static int N;
    static int M;
    static int H;
    static boolean[][][] isVisit = new boolean[101][101][101];

    static Queue<Node> tomatos = new LinkedList<>();
    static int totalTomato = 0;
    static int days = Integer.MIN_VALUE;

    static int[] dx = {0,0,-1,1,0,0};
    static int[] dy = {-1,1,0,0,0,0};
    static int[] dz = {0,0,0,0,-1,1};

    static void bfs() {
        for(Node tomato : tomatos) {
            isVisit[tomato.z][tomato.y][tomato.x] = true;
        }

        while(!tomatos.isEmpty()) {
            int curX = tomatos.peek().x;
            int curZ = tomatos.peek().z;
            int curDays = tomatos.peek().days;
            int curY = tomatos.poll().y;

            days = Math.max(curDays, days);

            for(int i = 0; i < 6; i++) {
                int nextX = curX + dx[i];
                int nextY = curY + dy[i];
                int nextZ = curZ + dz[i];
                int nextDays = curDays + 1;
                if(0 <= nextX && nextX < N && 0 <= nextY && nextY < M && 0 <= nextZ && nextZ < H &&
                        !isVisit[nextZ][nextY][nextX] && map[nextZ][nextY][nextX] == 0) {

                    isVisit[nextZ][nextY][nextX] = true;
                    tomatos.add(new Node(nextY, nextX, nextZ, nextDays));
                    totalTomato--;
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        H = sc.nextInt();

        for(int z = 0; z < H; z++) {
            for(int i = 0; i < M; i++) {
                for(int j = 0; j < N; j++) {
                    map[z][i][j] = sc.nextInt();
                    if(map[z][i][j] == 0) {
                        totalTomato++;
                    }
                    if(map[z][i][j] == 1) {
                        tomatos.add(new Node(i,j,z,0));
                    }
                }
            }
        }
        bfs();
        if(totalTomato == 0) {
            System.out.println(days);
        }else {
            System.out.println(-1);
        }
    }
}