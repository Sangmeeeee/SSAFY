package com.inteli.study.week5.d0225;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Problem6 {
    static int N,M;
    static int [][] map;
    static int[] dy={0,1,0,-1};
    static int[] dx={1,0,-1,0};
    static class Pair{
        int y;
        int x;
        public Pair(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
    static boolean checkAllRipe(){
        boolean flag=false;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if(map[i][j] ==0){//not ripen
                    flag=true;
                    break;
                }
            }
        }
        if(flag)return false;
        return true;
    }
    static boolean inbound(int y, int x){
        if(y<0 || N<=y || x<0 || M<=x)return false;
        return true;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str= br.readLine().split(" ");
        //input N,M
        N = Integer.parseInt(str[1]);
        M = Integer.parseInt(str[0]);
        map = new int [N][M];
        int time=0;
        int tomatoes=0;
        Queue<Pair> queue = new LinkedList<>();
        Queue<Pair> nextQueue = new LinkedList<>();

        //input map
        for(int i=0;i<N;i++){
            str = br.readLine().split(" ");
            for (int j = 0; j < M; j++) {
                map[i][j] = Integer.parseInt(str[j]);
                //ripe 먼저 queue 에 넣어주기.
                if(map[i][j]==1){
                    queue.offer(new Pair(i,j));
                }
                if(map[i][j]==0){
                    tomatoes++;
                }
            }
        }
        //sol
        while(!queue.isEmpty()){
            while(!queue.isEmpty()){
                Pair curPos = queue.poll();
                //4방탐색
                for(int i=0;i<4;i++){
                    int ny = curPos.y+dy[i];
                    int nx = curPos.x+dx[i];
                    //0 토마토이면 ripe진행 offer.
                    if(inbound(ny,nx) && map[ny][nx]==0) {
                        map[ny][nx] = 1;
                        nextQueue.offer(new Pair(ny, nx));
                    }
                }
            }
            if(!nextQueue.isEmpty())time++;
            queue = nextQueue;
            nextQueue = new LinkedList<>();
        }

        if(!checkAllRipe()){
            System.out.println(-1);
        }
        else System.out.println(time);
    }
}
//https://www.acmicpc.net/problem/7576
//토마토