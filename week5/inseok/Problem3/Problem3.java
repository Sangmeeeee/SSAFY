package com.inteli.study.week5.d0223;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Problem3_2 {
    static int N,L,R,X;
    static boolean [] visited;
    static int[] arr;
    static int answer=0;
    static void combination(int idx, int min, int max, int sum){
        int x = 0;
        if(min!=Integer.MAX_VALUE && max!=Integer.MIN_VALUE)
            x = max - min;//dist
        //basis  (성공)
        if(idx==N) {
            if(L<= sum && sum <=R && X<=x){
                answer++;
            }
            return;
        }
        //basis (실패)
        if(R<sum)return;

        //induct
        visited[idx]=true;
        combination(idx+1,Math.min(min,arr[idx]),Math.max(max,arr[idx]),sum+arr[idx]);
        visited[idx]=false;
        combination(idx+1,min,max,sum);
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        //input NLRX
        N=Integer.parseInt(st.nextToken());
        L=Integer.parseInt(st.nextToken());
        R=Integer.parseInt(st.nextToken());
        X=Integer.parseInt(st.nextToken());
        //init
        arr = new int[N];
        visited = new boolean[N];
        //input N
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(arr); //nlogn
        //sol
        combination(0,Integer.MAX_VALUE,Integer.MIN_VALUE,0);

        System.out.println(answer);
    }
}
