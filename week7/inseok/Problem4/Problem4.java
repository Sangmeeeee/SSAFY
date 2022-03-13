package com.inteli.study.week7.d0310;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Problem4 {
    static int LK(int k){
        int length = (int)Math.pow(2,k+3) -k -5;
        return length;
    }
    static void find(int n){
        int k=0;
        while(true){
            if(LK(k) < n){
                k++;
            }
            else
                break;
        }
        //A
        //이럴수가 있나?
        //if(n<LK(k-1)){
        //    find(n);
        //}
        //B
        if (n <= LK(k - 1) + k + 3) {
            if (n == LK(k - 1) + 1) {
                System.out.print("m");
            } else {
                System.out.print("o");
            }
        }
        //C
        else {
            find(n - LK(k - 1) - (k + 3));
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        find(N);
//        for(int i=1;i<N;i++){
//            find(i);
//            //System.out.println(LK(i));
//        }
    }
}
//m o o m o o o m o o m o o o o m o o m o o o m o o
//m o o m o o o m o o m o o o o m o o m o o o m o o o o o m