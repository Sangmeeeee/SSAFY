package com.inteli.study.week5.d0222;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
public class Problem2 {
    static char[][] table;
    static int N,M;
    static int answer =-1;
    static int[] dy={0,1,0,-1};
    static int[] dx={1,0,-1,0};
    static class Pair{
        int y;
        int x;
        public Pair(int y, int x) {
            this.y = y;
            this.x = x;
        }
        boolean equalsTo(Pair o){
            if(this.x==o.x && this.y ==o.y){
                return true;
            }
            return false;
        }

        @Override
        public String toString() {
            return "Pair{" +
                    "y=" + y +
                    ", x=" + x +
                    '}';
        }
    }
    static class Pos{
        Pair p1,p2;
        int level;
        public Pos(Pair p1, Pair p2) {
            this.p1 = p1;
            this.p2 = p2;
            this.level=0;
        }
        public Pos(Pair p1, Pair p2, int level) {
            this.p1 = p1;
            this.p2 = p2;
            this.level = level;
        }
        boolean equalsTo(Pos o){
            if(p1.equalsTo(o.p1) && p2.equalsTo(o.p2))return true;
            if(p1.equalsTo(o.p2) && p2.equalsTo(o.p1))return true;
            return false;
        }

        @Override
        public String toString() {
            return "Pos{" +
                    "p1=" + p1 +
                    ", p2=" + p2 +
                    ", level=" + level +
                    '}';
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        N = Integer.parseInt(str[0]);
        M = Integer.parseInt(str[1]);
        table = new char[N][M];
        Queue<Pos>queue = new LinkedList<>();
        List<Pos> visited = new LinkedList<>();
        Pair[] coins = new Pair[2];
        int coinIdx =0;
        //input
        for(int i=0; i<N ;i++){
            String line = br.readLine();
            table[i] = line.toCharArray();
            for (int j = 0; j < M ; j++) {
                if(table[i][j]=='o'){
                    coins[coinIdx]= new Pair(i,j);
                    coinIdx++;
                    table[i][j]='.';
                }
            }
        }
        //find Position
        queue.offer(new Pos(coins[0],coins[1]));
        visited.add(new Pos(coins[0],coins[1]));
        //BFS
        while(!queue.isEmpty()){
            if(answer!=-1)break;
            Pos curPos = queue.poll();
            if(curPos.level==10)break;
            //4방 가능한지
            for(int i=0;i<4;i++){
                Pos nPos = move(curPos,i);
                int ans = movable(curPos,nPos);

                if(ans==-1){
                    continue;
                }else if(ans==0){
                    answer = nPos.level;
                }else if(ans==1){
                    //움직일수는 있는데 visited 비교 해야함.
                    boolean flag=false;
                    for (int j = 0; j < visited.size(); j++) {
                        if(visited.get(j).equalsTo(nPos)){
                            flag=true;
                            break;
                        }
                    }
                    if(!flag){
                        //System.out.println(nPos);
                        queue.offer(nPos);
                        visited.add(nPos);
                    }
                }
            }
        }
        System.out.println(answer);
    }
    static int movable(Pos curPos,Pos nPos){
        int drop=0;
        int same=0;

        if(curPos.p1.equalsTo(nPos.p1)){
            same++;
        }
        if(curPos.p1.equalsTo(nPos.p2)){
            same++;
        }
        if(curPos.p2.equalsTo(nPos.p1)){
            same++;
        }
        if(curPos.p2.equalsTo(nPos.p2)){
            same++;
        }

        if(!inbound(nPos.p1))drop++;
        if(!inbound(nPos.p2))drop++;

        if(drop==1){return 0;}
        if(drop==2){return -1;}
        if(same==2){return -1;}
        return 1;
        //1: 가능 (움직일수 있는)
        //-1: 불가능(둘다 떨어지거나, 둘다 안움직이거나)
        //0 : 하나만 떨어지는 정답!
    }
    static Pos move(Pos curPos ,int dir){
        Pair p1 = new Pair(curPos.p1.y+dy[dir],curPos.p1.x+dx[dir]);
        Pair p2 = new Pair(curPos.p2.y+dy[dir],curPos.p2.x+dx[dir]);
        if(inbound(p1)){
            if(table[p1.y][p1.x]=='#'){
                p1 = new Pair(curPos.p1.y,curPos.p1.x);
            }
            else if (p1.equalsTo(curPos.p2)){
                if(inbound(new Pair(p1.y+dy[dir],p1.x+dx[dir]))){
                    if(table[p1.y+dy[dir]][p1.x+dx[dir]]=='#'){
                        p1 = new Pair(curPos.p1.y,curPos.p1.x);
                    }
                }
            }
        }
        if(inbound(p2)){
            if(table[p2.y][p2.x]=='#'){
                p2 = new Pair(curPos.p2.y,curPos.p2.x);
            }
            else if (p2.equalsTo(curPos.p1)){
                if(inbound(new Pair(p2.y+dy[dir],p2.x+dx[dir]))){
                    if(table[p2.y+dy[dir]][p2.x+dx[dir]]=='#'){
                        p2 = new Pair(curPos.p2.y,curPos.p2.x);
                    }
                }
            }
        }

        return new Pos(p1,p2, curPos.level+1);
    }
    static boolean inbound(Pair pair){
        if(pair.x<0 || M<=pair.x || pair.y<0 || N<=pair.y)return false;
        return true;
    }
}

//20분 bfs visited 발상 끝
//또 한시간 반만에 또 안된다.
//10회 이상 break; 해주니깐 55% 까지 갔는데 시간초과... 뭔가 돌고 있는게 아닐까..
//Pos p1p2 바뀌어도 eql 되도록 설정.