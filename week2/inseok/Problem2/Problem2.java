package com.inteli.study.week2.d0204;
import java.util.Deque;
import java.util.LinkedList;
import java.util.Queue;

class Problem2 {
    public int main(int bridge_length, int weight, int[] truck_weights) {
        int answer = 0;
        Queue<Integer> q =new LinkedList<>();//offer, poll, remove
        //init
        for(int i=0;i<bridge_length;i++){
            q.offer(0);
        }
        int bWeight=0;
        int tIdx=0;

        while(truck_weights.length != tIdx){
            bWeight-=q.poll();//pop
            if(bWeight + truck_weights[tIdx] <= weight){//able
                q.offer(truck_weights[tIdx]);
                bWeight+=truck_weights[tIdx];
                tIdx++;
                //System.out.println( (answer+1) +" " +(tIdx-1));
            }else{//unable
                q.offer(0);
                //bWeight+=0;
            }
            answer++;
        }
        answer+= bridge_length;//
        return answer;
    }
}
//2번
//큐
//Programmers
//https://programmers.co.kr/learn/courses/30/lessons/42583?language=java
//다리를 지나는 트럭
//Queue자체가 어려웠음 이거 정리 해두자.
//25분