package com.inteli.study.week5.d0225;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Problem5_1 {
    static int N,M;
    static int [][] map;
    static class Pair{
        int y,x;
        boolean bomb;
        int length;
        public Pair(int y, int x, boolean bomb ,int length) {
            this.y = y;
            this.x = x;
            this.bomb = bomb;
            this.length = length;
        }
    }
    static int [] dy = {0,1,0,-1};
    static int [] dx = {1,0,-1,0};
    static boolean inbound(int y,int x){
        if (0 <= y && y < N && 0 <= x && x < M) return true;
        else return false;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String [] str= br.readLine().split(" ");
        //input NM
        N = Integer.parseInt(str[0]);
        M = Integer.parseInt(str[1]);
        //input map
        map = new int[N][M];
        for(int i=0;i<N;i++){
            String line = br.readLine();
            for(int j=0;j<M;j++){
                map[i][j] = Integer.parseInt(Character.toString(line.charAt(j)));
            }
        }
        //Queue
        Queue<Pair>queue = new LinkedList<>();
        queue.offer(new Pair(0,0,false,1));//false라는게 아직 부시는거 안썼다는거.
        int length=-1;
        //sol
        while(!queue.isEmpty()){
            Pair curPair = queue.poll();
            if(curPair.y==N-1 && curPair.x==M-1){
                length = curPair.length;
                break;
            }
            for(int i=0;i<4;i++){
                int ny = curPair.y+dy[i];
                int nx = curPair.x+dx[i];
                if(inbound(ny,nx)){
                    if(map[ny][nx]==1){
                        if(curPair.bomb)continue;
                        queue.offer(new Pair(ny,nx,true, curPair.length+1));
                    }
                    if(map[ny][nx]==0)
                        queue.offer(new Pair(ny,nx, curPair.bomb,curPair.length+1));
                }
            }
        }
        //도착 하면
        System.out.println(length);
    }
}
