package com.inteli.study.week4.d0214;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Problem1 {
    static int [] rockSoon;
    static int [] rockYou;
    static int minColl=200001;
    static int cnt=0;
    static int N,H;
    static int[] levelColl;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        N = Integer.parseInt(line[0]);
        H = Integer.parseInt(line[1]);

        rockSoon = new int[H+1];// floor
        rockYou = new int[H+1];// ceiling

        //input
        for(int i=0;i<N/2;i++){
            rockSoon[Integer.parseInt(br.readLine())]++;
            rockYou [Integer.parseInt(br.readLine())]++;
        }

        findMinColl();//minColl,cnt
        System.out.println(minColl + " "+cnt);

    }
    static void findMinColl(){
        int coll = N/2;//level 0
        for(int i=1;i<=H;i++){
            //you 추가
            if( rockYou[H+1-i] != 0){//you
                coll += rockYou[H+1-i];
            }
            //col 계산
            if(coll < minColl){
                cnt = 1;
                minColl=coll;
            }
            else if(coll == minColl){
                cnt++;
            }
            //soon 빼기
            if( rockSoon[i] != 0){//soon
                coll -= rockSoon[i];
            }
        }
    }
}

//이게 이분 탐색?
//누적합이라는 힌트를 얻어서 문제 풀었다.