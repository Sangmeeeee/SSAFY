package com.inteli.study.week6.d0302;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Problem3 {
    static int N,M;
    static int [][] room;// 안청소 0 ,벽 1 , 청소하면 2
    static int[] dy = {-1, 0, 1, 0};//북동남서(오른쪽)
    static int[] dx = {0, 1, 0, -1};
    static int y,x,d;//device
    static boolean searchDirt(){
        boolean flag=false;
        //왼쪽 방향에 아직 청소하지 않은 공간이 존재하는지
        d--;
        if(d==-1)d=3;
        int ny = y+dy[d];
        int nx = x+dx[d];
        //아직 안청소 했으면 거기로 가버려
        if(flag = ((inbound(ny,nx))&&(room[ny][nx]==0)) ){
                flag=true;
                move(ny,nx);
        }

        return flag;
        //한다면 true
        // 이후그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
    }
    static void move(int ny, int nx){
        y = ny;
        x = nx;
    }
    static boolean moveBehind(){
        int bd=-1;
        switch(d){
            case 0:
                bd=2;
                break;
            case 1:
                bd=3;
                break;
            case 2:
                bd=0;
                break;
            case 3:
                bd=1;
                break;
        }
        int ny= y+dy[bd];
        int nx= x+dx[bd];
        //inbound & (!=1)
        if(inbound(ny,nx) && room[ny][nx]!=1){
            y = ny;
            x = nx;
            return true;
        }
        return false;
    }
    static boolean inbound(int y, int x){
        if( 0<=y&& y<N && 0<x && x<M)
            return true;
        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String [] str = br.readLine().split(" ");
        //input NM
        N = Integer.parseInt(str[0]);
        M = Integer.parseInt(str[1]);
        //init room,visited
        room = new int[N][M];
        //input device
        str = br.readLine().split(" ");
        y = Integer.parseInt(str[0]);
        x = Integer.parseInt(str[1]);
        d = Integer.parseInt(str[2]);
        //input room
        int clean=0;
        for (int i = 0; i < N; i++) {
            str = br.readLine().split(" ");
            for (int j = 0; j < M; j++) {
                room[i][j] =  Integer.parseInt(str[j]);
            }
        }
        //clean 시작
        while(true){
            //1. 현재 위치 청소
            if(room[y][x]==0){
                room[y][x]=2;
                clean++;
                //System.out.println("clean : "+y+" "+x+ " "+d);
            }
            boolean mFlag=false;
            for(int i=0;i<4;i++){
                if(searchDirt()) {
                    mFlag=true;
                    break;
                }
            }
            //4회 회전(4방 !=0) -> 후진
            if(!mFlag){
                //if able to move back-> go back
                //if not -> stop ;
                if(!moveBehind()){
                    break;
                }
                //System.out.println("back : "+d);
            }
        }
        System.out.println(clean);
    }
}
//https://www.acmicpc.net/problem/14503
//로봇청소기
//N*M 방(room)
//벽 or 칸
//바라보는 방향(dir)
//pos(r,c)
//순서대로 잘해봐라
//출력 : 청소 영역 개수

       /* 1 1 1 1 1 1 1 1 1 1
        1 0 0 0 0 0 0 0 0 1
        1 0 0 0 1 1 1 1 0 1
        1 0 0 1 1 0 0 0 0 1
        1 0 1 1 0 0 0 0 0 1
        1 0 0 0 0 0 0 0 0 1
        1 0 0 0 0 0 0 1 0 1
        1 0 0 0 0 0 1 1 0 1
        1 0 0 0 0 0 1 1 0 1
        1 0 0 0 0 0 0 0 0 1
        1 1 1 1 1 1 1 1 1 1*/