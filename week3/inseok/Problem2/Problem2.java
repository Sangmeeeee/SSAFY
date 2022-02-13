package com.inteli.study.week3.d0208;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Problem2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        PriorityQueue<Long> pq;
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();

        //testCase
        for(int testCase=0;testCase<T;testCase++){
            //init
            long totalPoint=(long)0;
            pq = new PriorityQueue<>();
            //input
            int K =Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < K; i++) {
                pq.offer(Long.parseLong(st.nextToken()));
            }
            //sol
            while(1<pq.size()){
                long a = pq.poll();
                long b = pq.poll();
                totalPoint += a+b;
                pq.add(a+b);
            }
            //output
            sb.append(totalPoint+"\n");
            //System.out.println(totalPoint);
        }
        System.out.print(sb.toString());
    }
}

//파일 합치기 3
//https://www.acmicpc.net/problem/13975
//15분