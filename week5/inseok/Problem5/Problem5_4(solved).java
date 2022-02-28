package com.inteli.study.week5.d0225;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Problem5_4 {
    static int N,M;
    static int [][] map;
    static boolean[][][] visited;
    static int [] dy = {0,1,0,-1};
    static int [] dx = {1,0,-1,0};
    static boolean inbound(int y,int x){
        if (0 <= y && y < N && 0 <= x && x < M) return true;
        else return false;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        //input NM
        N = Integer.parseInt(str[0]);
        M = Integer.parseInt(str[1]);
        //input map
        map = new int[N][M];
        visited = new boolean[N][M][2];
        for (int i = 0; i < N; i++) {
            String line = br.readLine();
            for (int j = 0; j < M; j++) {
                map[i][j] = Integer.parseInt(Character.toString(line.charAt(j)));
                if (map[i][j] == 1) {
                    visited[i][j][0] = true;
                    visited[i][j][1] = true;
                }
            }
        }
        //Queue
        Queue<int[]> queue = new LinkedList<>();
        int[] a = {0, 0, 0, 1};//y,x,bomb,length
        visited[0][0][0] = true;
        visited[0][0][1] = true;
        queue.offer(a);//false라는게 아직 부시는거 안썼다는거.//new Problem5.Pair(0,0,false,1)
        int length = -1;
        //sol
        while (!queue.isEmpty()) {
            int[] curPair = queue.poll();
            //visited[curPair[0]][curPair[1]]=true;
            if (curPair[0] == N - 1 && curPair[1] == M - 1) {
                length = curPair[3];
                break;
            }
            for (int i = 0; i < 4; i++) {
                int ny = curPair[0] + dy[i];
                int nx = curPair[1] + dx[i];
                if (inbound(ny, nx)) {
                    if (map[ny][nx] == 1) {
                        if (curPair[2] == 1) continue;
                        int[] newA = {ny, nx, 1, curPair[3] + 1};
                        queue.offer(newA);
                        //System.out.println(ny+" "+nx);
                    }
                    if (map[ny][nx] == 0) {
                        if (visited[ny][nx][curPair[2]] == false) {
                            int[] newA = {ny, nx, curPair[2], curPair[3] + 1};
                            queue.offer(newA);
                            visited[ny][nx][curPair[2]] = true;
                            //System.out.println(ny+" "+nx);
                        }
                    }
                }
            }
        }
        //도착 하면
        System.out.println(length);
    }
}
/*
6 4
0000
1110
1000
0001
0111
0010

 */