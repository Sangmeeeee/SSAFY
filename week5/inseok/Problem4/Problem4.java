package com.inteli.study.week5.d0224;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Problem4 {
    static int R,C;
    static char[][] map;//R+C , R C
    static boolean[][]visited;
    static class Pos{
//        int time;
        int y,x;
        /*public Pos(int time, int y, int x) {
            this.time = time;
            this.y = y;
            this.x = x;
        }*/
        public Pos(int y,int x){
            this.y=y;
            this.x=x;
        }
    }
    static int[] dy ={0,1,0,-1};
    static int[] dx ={1,0,-1,0};
    static void changeMap(){
        Queue<Pos>waterPos = new LinkedList<>();
        //원래 있던 물줄기들
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(map[i][j]=='*'){
                    waterPos.offer(new Pos(i,j));
                }
            }
        }
        //빼면서 확장시키기.
        while(!waterPos.isEmpty()){
            Pos cPos = waterPos.poll();
            expandWater(cPos);
        }
    }
    static void expandWater(Pos cPos){
        int ny,nx;
        for(int i=0;i<4;i++){
            ny = cPos.y + dy[i];
            nx = cPos.x + dx[i];
            if(inbound(ny,nx)){
                switch (map[ny][nx]){
                    case '.':
                        map[ny][nx]='*';
                        break;
                    //D,S,*,X
                    default:
                        break;
                }
            }
        }
        return;
    }
    static boolean inbound(int y, int x){
        if(x<0 || C<=x||y<0 || R<=y)return false;
        return true;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str ;
        str = br.readLine().split(" ");
        R = Integer.parseInt(str[0]);
        C = Integer.parseInt(str[1]);
        map = new char[R][C];
        visited = new boolean[R][C];
        Pos curS=null;
        //map그리기
        for (int i = 0; i < R; i++) {
            String line = br.readLine();
            for (int j = 0; j < C; j++) {
                map[i][j] = line.charAt(j);
                if(map[i][j]=='S'){
                    curS = new Pos(i,j);//
                }
            }
        }
        //사실 이거 bfs 하면서 time 바뀔때 map 갱신 하는게 더욱 효율적일것 같은데
        //효율이 아니라 이렇게 해야 된다!
        boolean kFlag=false;
        int answer=0;

        Queue<Pos>queue = new LinkedList<>();
        Queue<Pos>nextQueue = new LinkedList<>();
        queue.offer(curS);
        visited[curS.y][curS.x]=true;
        while(!queue.isEmpty()|| !nextQueue.isEmpty()){
            if(kFlag)break;
            changeMap();
            Pos cPos;
            while(!queue.isEmpty()){
                if(kFlag)break;
                cPos = queue.poll();
                for(int i=0;i<4;i++){
                    int ny = cPos.y+dy[i];
                    int nx = cPos.x+dx[i];
                    //inbound
                    if(inbound(ny,nx)){
                        //next not visited
                        if(!visited[ny][nx]){
                            if(map[ny][nx]=='*' || map[ny][nx] == 'X'){//벽이나 물이면 continue;
                                continue;
                            }
                            //offer
                            nextQueue.offer(new Pos(ny,nx));
                            //System.out.println(ny+" "+nx);
                            visited[ny][nx]=true;

                            //D면 flag세워서 break;
                            if(map[ny][nx]=='D'){
                                kFlag=true;
                                break;
                            }
                        }
                    }
                }
                //System.out.println("h");
            }
            queue = nextQueue;
            nextQueue = new LinkedList<>();
            answer++;
        }
        if(kFlag){
            System.out.println(answer);
        }
        else{
            System.out.println("KAKTUS");
        }
    }
}
//changeMap
//
