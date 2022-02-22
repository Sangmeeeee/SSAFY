package com.inteli.study.week4.d0216;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

public class Problem3 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] cmd;
        int N,M,L;
        int [] exist;
        PriorityQueue<Integer>priorityQueue = new PriorityQueue<>(Comparator.reverseOrder());//maxHeap
        //input
        cmd = br.readLine().split(" ");
        N = Integer.parseInt(cmd[0]);
        M = Integer.parseInt(cmd[1]);
        L = Integer.parseInt(cmd[2]);

        cmd = br.readLine().split(" ");
        exist = new int[N];
        for (int i = 0; i < N; i++) {
            exist[i] = Integer.parseInt(cmd[i]);
        }
        Arrays.sort(exist);

        //공백 priorityQueue(maxHeap) 저장
        priorityQueue.offer(exist[0]);
        int prev =exist[0];
        for(int i=1;i< exist.length;i++){
            prev = exist[i-1];
            priorityQueue.offer(exist[i]-prev);
        }
        priorityQueue.offer(L-exist[exist.length-1]);

        //M 회 빼면서 반쪽 해서 두개 넣기
        for(int i=0;i<M;i++){
            int length = priorityQueue.poll();
            if(length%2==0){
                priorityQueue.offer(length/2);
                priorityQueue.offer(length/2);
            }
            if(length%2==1){
                priorityQueue.offer((length/2)+1);
                priorityQueue.offer(length/2);
            }
        }
        System.out.println(priorityQueue.poll());
    }
}
