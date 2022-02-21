package com.inteli.study.week4.d0216;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;

public class Problem3_2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] cmd;
        int N,M,L;
        int [] exist;

        PriorityQueue<ShelterDist> priorityQueue = new PriorityQueue<>();//maxHeap
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

        //공백 priorityQueue(maxHeap) 생성
        priorityQueue.offer(new ShelterDist(exist[0]));
        int prev =exist[0];
        for(int i=1;i < exist.length;i++){
            prev = exist[i-1];
            priorityQueue.offer(new ShelterDist(exist[i]-prev));
        }
        priorityQueue.offer(new ShelterDist(L-exist[exist.length-1]));

        //m회 돌면서 num++ distEach 갱신
        for (int i = 0; i < M; i++) {
            ShelterDist sd = priorityQueue.poll();//
            sd.num++;
            if(sd.distTotal% sd.num==0){
                sd.distEach=sd.distTotal/sd.num;
            }else{
                sd.distEach=(sd.distTotal/sd.num)+1;
            }
            priorityQueue.offer(sd);

        }
        System.out.println(priorityQueue.poll().distEach);//여기서
    }
    static class ShelterDist implements Comparable<ShelterDist>{
        int distTotal;
        int num;
        int distEach;
        public ShelterDist(int distTotal) {
            this.distTotal = distTotal;
            this.num = 1;
            this.distEach = distTotal;
        }
        @Override
        public int compareTo(ShelterDist o) {//distEach내림차순
            return Integer.compare(o.distEach,this.distEach);
        }
    }
}
