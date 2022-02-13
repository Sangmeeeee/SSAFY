package com.inteli.study.week3.d0207;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

public class Problem1 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        PriorityQueue<Integer> priorityQueue = new PriorityQueue<>();

        int N = Integer.parseInt(br.readLine());
        int total=0;
        for (int i=0;i<N;i++){
            priorityQueue.add(Integer.parseInt(br.readLine()));
        }
        int a,b;
        while(priorityQueue.size()!=1){
            a=priorityQueue.poll();
            b=priorityQueue.poll();
            total += a+b;
            priorityQueue.add(a+b);
        }
        System.out.println(total);
    }
}
