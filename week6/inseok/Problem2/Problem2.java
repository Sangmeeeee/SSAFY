package com.inteli.study.week6.d0302;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Problem2 {
    //wheel : true S 1, false N 0
    static  boolean [][] wheel= new boolean[4][8];
    //num 번째 톱니 dir 방향으로 shift
    //dir 1: 시계방향, -1 : 반시계
    static void shift(int num, int dir){
        if(dir==1){
            boolean temp = wheel[num][7];
            for(int i=7;i>0;i--){
                wheel[num][i]= wheel[num][i-1];
            }
            wheel[num][0]=temp;
        }
        if(dir==-1){
            boolean temp = wheel[num][0];
            for(int i=0;i<7;i++){
                wheel[num][i]= wheel[num][i+1];
            }
            wheel[num][7]=temp;
        }
        //if(dir==0)donothing
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str ;
        int K;//cmd 횟수
        int point=0;//점수
        //input wheel
        for(int i=0;i<4;i++){
            str = br.readLine();
            for (int j = 0; j < 8; j++) {
                if(str.charAt(j)=='1'){
                    wheel[i][j]=true;
                }
            }
        }
        //input K
        K = Integer.parseInt(br.readLine());
        //input wheelNum & rotateDir
        for (int i = 0; i < K; i++) {
            String[] sstr=br.readLine().split(" ");
            int wheelNum =Integer.parseInt(sstr[0])-1;
            int rotateDir = Integer.parseInt(sstr[1]);
            //sol
            //link check (각각 dir 도 같이 결정)
            int[] linkMove = new int[4];//1 or -1
            linkMove[wheelNum]=rotateDir;
            if(0<wheelNum){
                //left
                for(int j=wheelNum;j>0;j--){
                    if(wheel[j][6]^wheel[j-1][2]){
                        linkMove[j-1]=linkMove[j]*-1;
                    }
                    else break;
                }
            }
            if(wheelNum<3){
                //right
                for(int j=wheelNum;j<3;j++){
                    if(wheel[j][2]^wheel[j+1][6]){
                        linkMove[j+1]=linkMove[j]*-1;
                    }
                    else break;
                }
            }
            //link 에 맞게 shift
            for (int j = 0; j < 4; j++) {
                 shift(j,linkMove[j]);
            }
        }
        //모든 move 이후 점수 올리기
        for (int j = 0; j < 4; j++) {
            if(wheel[j][0]){
                point += (1<<j);
            }
        }
        //print point
        System.out.println(point);
    }
}
//톱니바퀴
//https://www.acmicpc.net/problem/14891
//shift 연산? xor? 이방식 괜찮아 보이는데?
//xor로 어느 녀석 움직일지 배열로 1101 이런식으로 만들수 있겠다.
// 01'2'345'6'7
//N : false, S : true
// shift
//[0] 1 이 점수 기준.