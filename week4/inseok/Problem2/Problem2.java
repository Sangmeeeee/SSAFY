package com.inteli.study.week4.d0215;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Problem2_2 {
    static int N,M;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] cmd;
        StringBuilder sb = new StringBuilder();
        int testCase=0;
        while(true){
            //input
            cmd = br.readLine().split(" ");
            N = Integer.parseInt(cmd[0]);//vertex
            M = Integer.parseInt(cmd[1]);//edge
            if(N==0 && M==0)break;
            testCase++;
            int [] arr = new int [N+1];
            for (int i = 0; i < M; i++) {
                cmd =br.readLine().split(" ");
                int smallIdx= Integer.parseInt(cmd[0]);
                int bigIdx = Integer.parseInt(cmd[1]);
                if(bigIdx<smallIdx){//스왑
                    int temp = smallIdx;
                    smallIdx = bigIdx;
                    bigIdx = temp;
                }
                int smallHead=findHead(arr,smallIdx);
                int bigHead = findHead(arr, bigIdx);
                if(bigHead<smallHead){//스왑
                    int temp = smallHead;
                    smallHead = bigHead;
                    bigHead = temp;
                }
                if(smallHead==bigHead){
                    arr[smallHead]=-1;
                    continue;
                }
                Union(arr,smallHead,bigHead);
            }
            //print
            for(int i=1;i<=N;i++){
                System.out.print(arr[i]+" ");
            }
            System.out.println();
            //
            int treeNum=0;
            for(int i=1;i<=N;i++){
                if(arr[i] == 0){
                    treeNum++;
                }
            }
            sb.append("Case "+testCase+": ");
            appendByNum(sb,treeNum);
        }
        System.out.print(sb.toString());
    }
    static int findHead(int[]arr,int idx){
        if(arr[idx]==0||arr[idx]==-1) return idx;
        else return arr[idx];
    }
    static void Union(int[] arr, int anc, int anc2 ){
        arr[anc2]=anc;
        for(int i=anc2+1;i<=N;i++){
            if(arr[i]==anc2)arr[i]=anc;
        }
        return;
    }
    static void appendByNum(StringBuilder stringBuilder,int treeNum){
        //A forest of N trees.
        //There is one tree.
        //No trees.
        switch (treeNum){
            case 0:
                stringBuilder.append("No trees.\n");
                break;
            case 1:
                stringBuilder.append("There is one tree.\n");
                break;
            default:
                stringBuilder.append("A forest of "+treeNum+" trees.\n");
                break;
        }
    }
}
