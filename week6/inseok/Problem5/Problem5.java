package com.inteli.study.week6.d0306;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Problem5 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //input N
        int N = Integer.parseInt(br.readLine());
        int[] weight = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine()," ");
        //input weight
        for(int i=0;i<N;i++){
            weight[i] = Integer.parseInt(st.nextToken());
        }
        //sol
        Arrays.sort(weight);
        //int sum[] = new int[N];//가능(앞에서부터 누적으로 할건데)
        int sum=0;
        int idx=0;
        while( idx<N && sum+1 >= weight[idx]){
            //sum 갱신 후 idx 갱신
            sum+=weight[idx++];
        }
        System.out.println(sum+1);
    }
}
//이런걸 그리디라 하는구나.
//O(nlogn)
//딱 못만드는거 눈에 들어옴.

/*
2
1 2
정답 4 여기에서 indexOutOfBound
*/