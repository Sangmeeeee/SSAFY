package com.inteli.study.week4.d0217;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Problem4 {
    static List<Integer>[] adjList;
    static boolean[] visited;
    static boolean depthFlag=false;
    static void dfs(int idx, int depth){
        //basis
        if(depthFlag)return;
        if(depth==5){
            depthFlag=true;
            return ;
        }
        //inductive part
        for(int i=0;i<adjList[idx].size();i++){//여기 좀 더 이쁘게 변수 하면..
            if(!visited[adjList[idx].get(i)]){//아직 안들렸다면
                visited[adjList[idx].get(i)] = true;
                //System.out.println(idx+"->"+adjList[idx].get(i));
                dfs(adjList[idx].get(i), depth+1);
                visited[adjList[idx].get(i)] = false;
                //if(depthFlag)return;//조금이라도 빨리 다들 나오세요
            }
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] cmd;
        int[] edge = new int[2];
        int N,M;

        cmd = br.readLine().split(" ");
        N =Integer.parseInt(cmd[0]);//# of vertex
        M =Integer.parseInt(cmd[1]);//# of edge
        adjList = new ArrayList[N];//아하? 모양새가 죄금 신기.
        visited = new boolean[N];
        for(int i=0;i<N;i++){
            adjList[i] = new ArrayList<>();
        }
        /*
        for(List arrayList : adjList){
            arrayList = new ArrayList();
        }
        */

        for(int i=0;i<M;i++){
            cmd = br.readLine().split(" ");
            edge[0] = Integer.parseInt(cmd[0]);
            edge[1] = Integer.parseInt(cmd[1]);
            adjList[edge[0]].add(edge[1]);
            adjList[edge[1]].add(edge[0]);//양방향
        }
        /*for (int j = 0; j < N; j++) {
            for(int i=0;i<adjList[j].size();i++){
                System.out.print(adjList[j].get(i)+ " ");
            }
            System.out.println();
        }*/
        //sol
        for(int i=0;i<N;i++){
            if(depthFlag) break;

            visited[i] = true;
            dfs(i, 1);
            visited[i] = false;
        }
        if(depthFlag) System.out.println(1);
        else System.out.println(0);
    }

}
//10분 pseudo
//35분 근데 뭔가 이상..
//50분